class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>>dp(n+10,vector<int>(m+10,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                dp[i][j]=dp[i+1][j]+dp[i][j+1]+matrix[i][j];
                dp[i][j]-=dp[i+1][j+1];
            }
        }
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //start from cell (i,j)
                
                for(int rowb=i;rowb<n;rowb++)
                {
                    for(int colb=j;colb<m;colb++)
                    {
                        int available=dp[i][j];
                        available-=dp[i][colb+1];
                        available-=dp[rowb+1][j];
                        available+=dp[rowb+1][colb+1];
                        if(available==target)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
