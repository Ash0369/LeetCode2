class Solution 
{
public:
    bool areSimilar(vector<vector<int>>& mat, int k) 
    {
        
        int n=mat.size();
        int m=mat[0].size();
        k=k%m;
        
        for(int i=0;i<n;i++)
        {
            
            if(i%2==0)
            {
                vector<int>nz(m);
                for(int j=0;j<m;j++)
                {
                    int np=(j-k+m)%m;
                    nz[np]=mat[i][j];
                }
                if(nz!=mat[i])
                {
                    return false;
                }
            }
            else{
                 vector<int>nz(m);
                for(int j=0;j<m;j++)
                {
                    int np=(j+k)%m;
                    nz[np]=mat[i][j];
                }
                if(nz!=mat[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
