class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>>ans;
        map<vector<int>,vector<string>>mp;
        for(auto x:strs)
        {
            vector<int>dp(26,0);
            for(auto y:x)
            {
                dp[y-'a']++;
            }
            mp[dp].push_back(x);
        }
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
