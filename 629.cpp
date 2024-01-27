int mod=1000000007;
#define ll long long
ll mod_sub(ll int a, ll int b){a=a%mod;b=b%mod;return (((a - b)%mod)+mod)%mod;}
class Solution 
{
public:
    int kInversePairs(int n, int k) 
    {
        vector<vector<int>>dp(n+10,vector<int>(k+10,0));
        vector<vector<int>>pdp(n+10,vector<int>(k+10,0));
        dp[1][0]=1;
        pdp[1][0]=1;
        for(int i=1;i<=k;i++)
        {
            pdp[1][i]=pdp[1][i-1]+dp[1][i];
        }
        for(int i=2;i<=n;i++)
        {
            dp[i][0]=1;
            for(int j=1;j<=k;j++)
            {
                ll int offer=pdp[i-1][j];
                ll int not_offer=0;
                if(j>=i)
                {
                    not_offer=pdp[i-1][j-i];
                    offer=mod_sub(offer,not_offer);
                }
                dp[i][j]=(dp[i][j]+offer)%mod;
            }
            pdp[i][0]=1;
            for(int j=1;j<=k;j++)
            {
                pdp[i][j]=(pdp[i][j-1]+dp[i][j])%mod;
            }
        }
        return dp[n][k];
    }
};
