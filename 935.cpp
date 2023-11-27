int mod=1000000007;
#define ll long long
ll int dp[5001][12];
ll int dfs(int start,int move,vector<vector<int>>&edge)
{
    if(move==0)
    {
        return 1;
    }
    if(start==5)
    {
        return 0;
    }
    if(dp[move][start]!=-1)
    {
        return dp[move][start];
    }
    ll int ans=0;
    for(auto x:edge[start])
    {
        ans=(ans+dfs(x,move-1,edge))%mod;
    }
    return dp[move][start]=ans;
}
class Solution 
{
public:
    int knightDialer(int n) 
    {
        vector<vector<int>>edge(10);
        edge[0]={6,4};
        edge[1]={6,8};
        edge[2]={7,9};
        edge[3]={4,8};
        edge[4]={3,9,0};
        edge[6]={1,7,0};
        edge[7]={6,2};
        edge[8]={1,3};
        edge[9]={4,2};
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=9;j++)
            {
                dp[i][j]=-1;
            }
        }
        ll int ans=0;
        for(int i=0;i<=9;i++)
        {
            ans=(ans+dfs(i,n-1,edge))%mod;
        }
        return ans;
    }
};
