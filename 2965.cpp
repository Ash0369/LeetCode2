class Solution 
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        map<int,int>mp;
        int n=grid.size();
        int t=1;
        for(int i=1;i<=(n*n);i++)
        {
            mp[i]++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                mp[grid[i][j]]--;   
            }
        }
        vector<int>ans(2,0);
        for(auto x:mp)
        {
            if(x.second<0)
            {
                ans[0]=x.first;
            }
            if(x.second>0)
            {
                ans[1]=x.first;
            }
        }
        return ans;
    }
};
