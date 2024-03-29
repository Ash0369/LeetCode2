#define ll long long
class Solution 
{
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int mx=nums[0];
        for(auto x:nums)
        {
            mx=max(mx,x);
        }
        
        int n=nums.size();
        vector<int>dp(n,0);
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==mx)
            {
                dp[i]=1;
            }
            if(i>0)
            {
                dp[i]+=dp[i-1];
            }
        }
        
        ll int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int curr=dp[i];
            if(curr<k)
            {
                continue;
            }
            
            //Find when we have curr-k
            
            auto lb=lower_bound(dp.begin(),dp.end(),curr-k+1)-dp.begin();
            ans+=lb+1;
        }
        return ans;
    }
};
