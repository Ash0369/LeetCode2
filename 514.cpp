class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m=ring.size();
        int n=key.size();
        
        vector<vector<int>>dp(n+10,vector<int>(m+10,1e9));
        
        for(int i=0;i<n;i++)
        {
            //I am ith place now i want to increase
            for(int j=0;j<m;j++)
            {
                if(ring[j]==key[i])
                {
                    if(i==0)
                    {
                        int cost=j;
                        cost=min(cost,m-j);
                        dp[i][j]=1+cost;
                        continue;
                    }
                    for(int k=0;k<m;k++)
                    {
                        if(ring[k]==key[i-1])
                        {
                            //So i can transfer
                            int cost=dp[i-1][k];
                            int a1=abs(k-j);
                            int a2=0;
                            a2=m-max(k,j);
                            a2+=min(k,j);
                            a1=min(a1,a2);
                            cost+=a1;
                            dp[i][j]=min(dp[i][j],1+cost);
                        }
                    }
                }
            }
        }
        int ans=1e9;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};
