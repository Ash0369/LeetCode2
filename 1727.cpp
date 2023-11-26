class Solution 
{
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==1)
                {
                    if(i-1>=0)
                    {
                        dp[i][j]=dp[i-1][j]+1;
                    }
                    else
                    {
                        dp[i][j]=1;
                    }
                    
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            sort(dp[i].begin(),dp[i].end());
            reverse(dp[i].begin(),dp[i].end());
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,(j+1)*dp[i][j]);
            }
        }
        return ans;
    }
};
