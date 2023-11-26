class dsu
{
    public:
    vector<int>rank,parent,size;
    
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
class Solution 
{
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) 
    {
        int n=nums.size();
        dsu ds(n+5);
        
        set<pair<int,int>>st;
        for(int i=0;i<n;i++)
        {
            st.insert({nums[i],i});
        }
        
        while(st.size()>1)
        {
            int val=(*st.begin()).first;
            int index=(*st.begin()).second;
            
            queue<pair<int,int>>q;
            
            auto lb=st.lower_bound({val+limit+1,-1});
            if(lb==st.begin())
            {
                st.erase(*lb);
                continue;
            }
            lb--;
            
            while(true)
            {
                q.push(*lb);
                ds.union_by_rank(index,(*lb).second);
                if(lb==st.begin())
                {
                    break;
                }
                lb--;
            }
            if(q.size()>1)
            {
                q.pop();
            }
            while(!q.empty())
            {
                st.erase(q.front());
                q.pop();
            }
        }
        
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            int p=ds.find_parent(i);
            mp[p].push_back(nums[i]);
        }
        for(auto &x:mp)
        {
            sort(x.second.begin(),x.second.end());
            reverse(x.second.begin(),x.second.end());
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int p=ds.find_parent(i);
            ans.push_back(mp[p].back());
            mp[p].pop_back();
        }
        return ans;    

    }
};
