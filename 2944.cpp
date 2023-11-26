class Solution 
{
public:
    int minimumCoins(vector<int>& prices) 
    {
        int n=prices.size();
        vector<int>dp(n+1,1e9);
        dp[n-1]=prices[n-1];
        dp[n]=0;
        for(int i=n-2;i>=0;i--)
        {
            dp[i]=1e9;
            for(int j=i;j<min(n,i+i+2);j++)
            {
                dp[i]=min(dp[i],prices[i]+dp[j+1]);
            }
        }
        return dp[0];
    }
};
