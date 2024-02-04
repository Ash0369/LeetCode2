class Solution 
{
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) 
    {
        int m=image.size();
        int n=image[0].size();
        vector<vector<pair<int,int>>>dp(m,vector<pair<int,int>>(n,{0,0}));
        
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                if(i+2<m && j+2<n)
                {
                    int tot=0;
                    bool res=true;
                    for(int x=i;x<=i+2;x++)
                    {
                        for(int y=j;y<=j+2;y++)
                        {
                            tot+=image[x][y];
                            if(y<j+2 && abs(image[x][y]-image[x][y+1])>threshold)
                            {
                                res=false;
                            }
                            if(y>j && abs(image[x][y]-image[x][y-1])>threshold)
                            {
                                res=false;
                            }
                            if(x<i+2 && abs(image[x][y]-image[x+1][y])>threshold)
                            {
                                res=false;
                            }
                            if(x>i && abs(image[x][y]-image[x-1][y])>threshold)
                            {
                                res=false;
                            }
                            
                            
                        }
                    }
                    if(res==false)
                    {
                        continue;
                    }
                    int av=tot/9;
                    for(int x=i;x<=i+2;x++)
                    {
                        for(int y=j;y<=j+2;y++)
                        {
                            dp[x][y].first+=av;
                            dp[x][y].second++;
                        }
                    }
                    
                }
            }
        }
        
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j].second==0)
                {
                    ans[i][j]=image[i][j];
                }
                else{
 
                    ans[i][j]=dp[i][j].first/dp[i][j].second;
                }
            }
        }
        return ans;
    }
};
