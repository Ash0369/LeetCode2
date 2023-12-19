class Solution 
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        int dx[8]={-1,0,1,1,1,0,-1,-1};
        int dy[8]={1,1,1,0,-1,-1,-1,0};
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int tot=0;
                int l=0;
                
                for(int k=0;k<8;k++)
                {
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(x>=0 && y>=0 && x<n && y<m)
                    {
                        tot+=img[x][y];
                        l++;
                    }
                }
                tot+=img[i][j];
                l++;
                ans[i][j]=tot/l;
            }
        }
        return ans;
    }
};
