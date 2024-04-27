class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int n=3;
        for(int i=0;i<=1;i++)
        {
            for(int j=0;j<=1;j++)
            {
                map<char,int>mp;
                mp[grid[i][j]]++;
                mp[grid[i][j+1]]++;
                mp[grid[i+1][j]]++;
                mp[grid[i+1][j+1]]++;
                
                for(auto x:mp)
                {
                    if(x.second>=3)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
