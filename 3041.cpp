class Solution 
{
public:
    int maxSelectedElements(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        vector<vector<int>>dp(n+10,vector<int>(5,0));
        
        dp[0][0]=1;
        dp[0][1]=1;
        int ans=1;
        for(int i=1;i<n;i++)
        {
            dp[i][0]=1;
            dp[i][1]=1;
            if(nums[i-1]+1==nums[i])
            {
                dp[i][0]=1+dp[i-1][0];
            }
            if(nums[i-1]+2==nums[i])
            {
                dp[i][0]=1+dp[i-1][1];
            }
            
            if(nums[i-1]==nums[i])
            {
                dp[i][1]=1+dp[i-1][0];
            }
            if(nums[i-1]+1==nums[i])
            {
                dp[i][1]=1+dp[i-1][1];
            }
            if(nums[i]==nums[i-1])
            {
                dp[i][0]=max(dp[i][0],dp[i-1][0]);
                dp[i][1]=max(dp[i][1],dp[i-1][1]);
            }
            ans=max(ans,max(dp[i][0],dp[i][1]));
        }
        return ans;
        
    }
};
