void dfs(int n,int index,vector<vector<int>>&graph,vector<int>&dp,vector<int>&ans)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,index});
    dp[index]=0;
    while(!pq.empty())
    {
        auto node=pq.top();
        pq.pop();
        
        for(auto x:graph[node.second])
        {
            if((dp[x]>(1+node.first)))
            {
                dp[x]=1+node.first;
                pq.push({dp[x],x});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i==index || dp[i]>n)
        {
            continue;
        }
        ans[dp[i]]++;
    }
    
    
}
class Solution 
{
public:
    vector<int> countOfPairs(int n, int x, int y) 
    {
        vector<vector<int>>graph(n+1);
        for(int i=1;i<n;i++)
        {
            graph[i].push_back(i+1);
            graph[i+1].push_back(i);
        }
        graph[x].push_back(y);
        graph[y].push_back(x);
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++)
        {
            vector<int>dp(n+1,1e9);
            dfs(n,i,graph,dp,ans);
        }
        reverse(ans.begin(),ans.end());
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
