class Solution 
{
public:
    int countNicePairs(vector<int>& nums) 
    {
        map<int,int>mp;
        int ans=0;
        int mod=1000000007;
        for(auto x:nums)
        {
            string s=to_string(x);
            reverse(s.begin(),s.end());
            int t=x-stoi(s);
            ans=(ans+mp[t])%mod;
            mp[t]++;
        }
        return ans;
    }
};
