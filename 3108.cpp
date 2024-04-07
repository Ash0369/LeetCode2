class dsu
{
    vector<int>rank,parent,size;
    public:
    dsu(int n)
    {
        rank.resize(n+1,0);//Work for both 0 or 1 based
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int find_parent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=find_parent(parent[node]);//Path compression
    }

    void union_by_rank(int u,int v)
    {
        int ultimate_parent_u=find_parent(u);
        int ultimate_parent_v=find_parent(v);

        if(ultimate_parent_u==ultimate_parent_v)
        {
            //They are belonging to same component
            return;
        }
        else if(rank[ultimate_parent_u]<=rank[ultimate_parent_v])
        {
            parent[ultimate_parent_u]=ultimate_parent_v;
        }
        else if(rank[ultimate_parent_u]>rank[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
        }
    }

    void union_by_size(int u,int v)
    {
        int ultimate_parent_u=find_parent(u);
        int ultimate_parent_v=find_parent(v);

        if(ultimate_parent_u==ultimate_parent_v)
        {
            //They are belonging to same component
            return;
        }
        else if(size[ultimate_parent_u]<=size[ultimate_parent_v])
        {
            parent[ultimate_parent_u]=ultimate_parent_v;
            size[ultimate_parent_v]+=size[ultimate_parent_u];
        }
        else if(size[ultimate_parent_u]>size[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
            size[ultimate_parent_u]+=size[ultimate_parent_v];
        }
    }
};

int dfs(int index,vector<vector<vector<int>>>&graph,vector<int>&dp)
{
    dp[index]=1;
    int a=-1;
    for(auto x:graph[index])
    {
        if(a==-1)
        {
            a=x[1];
        }
        else{
            a=a&x[1];
        }
        if(dp[x[0]]==0)
        {
            
            int v=dfs(x[0],graph,dp);
            if(v!=-1)
            {
                a=a&v;
            }
        }
    }
    return a;
}
class Solution 
{
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
    {
        dsu ds(n+2);
        vector<vector<vector<int>>>graph(n+10);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            ds.union_by_rank(edges[i][0],edges[i][1]);
        }
        
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[ds.find_parent(i)]=1;
        }
        vector<int>dp(n,0);
        for(auto x:mp)
        {
            
            int v=dfs(x.first,graph,dp);
            //cout<<x.first<<" "<<v<<endl;
            mp[x.first]=v;
        }
        
        vector<int>ans;
        
        for(auto x:query)
        {
            int a=x[0];
            int b=x[1];
            
            if(a==b)
            {
                ans.push_back(0);
                continue;
            }
            
            if(ds.find_parent(a)==ds.find_parent(b))
            {
                ans.push_back(mp[ds.find_parent(a)]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
