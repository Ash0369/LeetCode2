#define ll long long
class Solution 
{
public:
    long long countBadPairs(vector<int>& nums) 
    {
        map<int,int>mp;
        ll int n=nums.size();
        ll int ans=0;
        for(int i=0;i<n;i++)
        {
            int z=nums[i]-i;
            ans=(ans+mp[z]);
            mp[z]++;
        }
        return (n*(n-1)/2)-ans;
    }
};
