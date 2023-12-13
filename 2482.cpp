class Solution 
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<int>oner(m,0);
        vector<int>onec(n,0);
        vector<int>zeror(m,0);
        vector<int>zeroc(n,0);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    oner[i]++;
                    onec[j]++;
                }
                else
                {
                    zeror[i]++;
                    zeroc[j]++;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i][j]=oner[i]+onec[j]-zeror[i]-zeroc[j];
            }
        }
        return grid;
    }
};
