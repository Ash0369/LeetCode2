#define ll long long
void dfs(vector<int>&dp,int n)
{
    dp[1]=1;
    dp[0]=1;
    for(ll int i=2;i<=n;i++)
    {
        if(dp[i]==0)
        {
            for(ll int j=i*i;j<=n;j=j+i)
            {
                dp[j]=1;
            }
        }
    }
}
class Solution 
{
public:
    int countPrimes(int n) 
    {
        vector<int>dp(n+10,0);
        if(n==0)
        {
            return 0;
        }
        dfs(dp,n);
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i]+dp[i-1];
        }
        if(n==0)
        {
            return 0;
        }
        
        return n-dp[n-1];
    }
};
