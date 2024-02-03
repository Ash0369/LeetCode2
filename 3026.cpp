#define ll long long
class Solution 
{
public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<ll int>dp(n,nums[0]);
        map<ll int,vector<int>>index;
        index[nums[0]].push_back(0);
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]+nums[i];
            index[nums[i]].push_back(i);
        }
        
        ll int ans=-1e18;
        
        for(int i=0;i<n;i++)
        {
            ll int val=nums[i];
            ll int s=val+k;
            
            for(auto x:index[s])
            {
                ll int a=min(i,x);
                ll int b=max(i,x);
                
                ll int s1=dp[b];
                ll int s2=0;
                if(a>0)
                {
                    s2=dp[a-1];
                }
                
                ans=max(ans,s1-s2);
            }
        }
        if(ans==(-1e18))
        {
            return 0;
        }
        return ans;
        
    }
};
