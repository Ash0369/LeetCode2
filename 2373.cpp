class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        
        vector<vector<int>>ans(n-2,vector<int>(n-2));
        
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                int m=grid[i][j];
                for(int k1=i;k1<=i+2;k1++)
                {
                    for(int k2=j;k2<=j+2;k2++)
                    {
                        m=max(m,grid[k1][k2]);
                    }
                }
                ans[i][j]=m;
            }
        }
        return ans;
    }
};
