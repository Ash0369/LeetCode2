class Solution 
{
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        map<int,int>mp;
        set<int>st;
        for(auto x:matches)
        {
            st.insert(x[0]);
            st.insert(x[1]);
            
            mp[x[1]]++;
        }
        vector<vector<int>>ans(2);
        
        for(auto x:st)
        {
            if(mp[x]==0)
            {
                ans[0].push_back(x);
            }
            if(mp[x]==1)
            {
                ans[1].push_back(x);
            }
        }
        return ans;
    }
};
