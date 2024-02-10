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
        ll int ans=-1e18;
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]+nums[i];
            
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
            s=val-k;
            
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
            
            if(index[nums[i]].size()>0)
            {
                ll int ps=0;
                if(index[nums[i]].back()-1>=0)
                {
                    ps=dp[index[nums[i]].back()-1];
                }
                if(ps>=dp[i-1])
                {
                    index[nums[i]].pop_back();
                    index[nums[i]].push_back(i);
                }
            }
            else
            {
                index[nums[i]].push_back(i);
            }
            
        }
        if(ans==(-1e18))
        {
            return 0;
        }
        return ans;
        
    }
};
