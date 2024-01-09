class Solution 
{
public:
    int minOperations(vector<int>& nums, int k) 
    {
        int ans=0;
        int n=nums.size();
        vector<int>dp(40,0);
        for(auto x:nums)
        {
            int ele=x;
            for(int j=0;j<=29;j++)
            {
                if((ele&(1<<j)))
                {
                    dp[j]++;
                }
            }
        }
        for(int i=29;i>=0;i--)
        {
            if((k&(1<<i)))
            {
                if(dp[i]%2!=0)
                {
                    
                }
                else
                {
                    ans++;
                }
            }
            else
            {
                if(dp[i]%2==0)
                {
                    
                }
                else
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
