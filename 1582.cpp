class Solution 
{
public:
    int numSpecial(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        vector<int>row(n,0);
        vector<int>col(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                row[i]+=mat[i][j];
                col[j]+=mat[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    if((row[i]+col[j])==2)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
