mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    map<int,vector<int>>mp;
    Solution(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) 
    {
        int sz=mp[target].size();
        return mp[target][uniform_int_distribution<int>(0,sz-1)(rng)];  
    }
};
