#define ll long long
ll int dfs(int index,vector<vector<ll int>>&graph,string &source, string &target,vector<ll int>&dp,map<string,int>&mp,map<int,set<int>>&st)
{
    int y=source.size();
    if(index>=y)
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    ll int c=1e18;
    for(auto x:st[source[index]-'a'])
    {
        int len=x;
        if(index+len>y)
        {
            break;
        }
        string curr=source.substr(index,len);
        string to=target.substr(index,len);
        if(mp.find(curr)==mp.end() || mp.find(to)==mp.end())
        {
            continue;
        }
        int index1=mp[curr];
        int index2=mp[to];
        if(graph[index1][index2]<1e15)
        {
            c=min(c,graph[index1][index2]+dfs(index+len,graph,source,target,dp,mp,st));
        }
        
    }
    if(source[index]==target[index])
    {
        c=min(c,dfs(index+1,graph,source,target,dp,mp,st));
    }
    return dp[index]=c;
}
class Solution 
{
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) 
    {
        unordered_map<string,int>mp;
        int sz=original.size();
        set<int>st;
        vector<vector<ll int>>graph(2*sz,vector<ll int>(2*sz,1e12));
        int alloted=0;
        for(int i=0;i<original.size();i++)
        {
            string a=original[i];
            string b=changed[i];
            
            if(mp.find(a)==mp.end())
            {
                mp[a]=alloted;
                alloted++;
            }
            if(mp.find(b)==mp.end())
            {
                mp[b]=alloted;
                alloted++;
            }
            int sz=a.size();
            st.insert(sz);
            int index1=mp[a];
            int index2=mp[b];
            
            graph[index1][index2]=min(graph[index1][index2],1LL*cost[i]);
        }
        for(int x=0;x<alloted;x++)
        {
            for(int y=0;y<alloted;y++)
            {
                if(graph[y][x]>=1e12)
                {
                    continue;
                }
                for(int z=0;z<alloted;z++)
                {
                    graph[y][z]=min(graph[y][z],graph[y][x]+graph[x][z]);
                }
            }
        }
        int n=source.size();
        vector<ll int>dp(n+2,0);
        ll int ans=0;
        int y=source.size();
        for(int i=y-1;i>=0;i--)
        {
             ll int c=1e18;
             for(auto &x:st)
             {
                 int len=x;
                 if(i+len>y)
                 {
                     break;
                 }
                 string curr=source.substr(i,len);
                 string to=target.substr(i,len);
                 if(mp.find(curr)==mp.end() || mp.find(to)==mp.end())
                 {
                     continue;
                 }
                 int index1=mp[curr];
                 int index2=mp[to];
                 if(graph[index1][index2]<1e15)
                 {
                     c=min(c,graph[index1][index2]+dp[i+len]);
                 }
        
             }
             if(source[i]==target[i])
             {
                 c=min(c,dp[i+1]);
             }
            dp[i]=c;
        }
        ans=dp[0];
        if(ans>=1e12)
        {
            return -1;
        }
        return ans;
    }
};
