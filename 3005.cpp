class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        int mx=0;
        for(auto x:nums)
        {
            mp[x]++;
            mx=max(mx,mp[x]);
        }
        int cnt=0;
        for(auto x:mp)
        {
            if(x.second==mx)
            {
                cnt++;
            }
        }
        return cnt*mx;
    }
};
