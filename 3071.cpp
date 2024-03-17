int dfs(vector<vector<int>>&grid,int a,int b)
{
    int ans=0;
    int n=grid.size();
    
    int m=n/2;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j && i<=m)
            {
                if(grid[i][j]==a)
                {
                    
                }
                else
                {
                    ans++;
                }
            }
            else if(i+j==n-1 && i<=m)
            {
                if(grid[i][j]==a)
                {
                    
                }
                else
                {
                    ans++;
                }
            }
            else if(i>=m && j==m )
            {
                if(grid[i][j]==a)
                {
                    
                }
                else
                {
                    ans++;
                }
            }
            else
            {
                if(grid[i][j]==b)
                {
                    
                }
                else
                {
                    ans++;
                }
            }
            
        }
    }
    return ans;
}
class Solution 
{
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid)
    {
        int ans=100000;
        for(int i=0;i<=2;i++)
        {
            for(int j=0;j<=2;j++)
            {
                if(i==j)
                {
                    continue;
                }
                ans=min(ans,dfs(grid,i,j));
            }
        }
        return ans;
    }
};
