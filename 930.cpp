class Solution 
{
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        map<int,int>mp;
        mp[0]=1;
        int tot=0;
        int ans=0;
        for(auto x:nums)
        {
            tot+=x;
            int need=tot-goal;
            ans+=mp[need];
            mp[tot]++;
        }
        return ans;
    }
};
