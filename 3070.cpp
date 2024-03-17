class Solution 
{
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]=grid[i][j];
                if(i-1>=0)
                {
                    dp[i][j]+=dp[i-1][j];
                }
                if(j-1>=0)
                {
                    dp[i][j]+=dp[i][j-1];
                }
                if(i>0 && j>0)
                {
                    dp[i][j]-=dp[i-1][j-1];
                }
                if(dp[i][j]<=k)ans++;
                    
            }
        }
        return ans;
    }
};
