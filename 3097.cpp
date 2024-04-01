bool check(map<int,int>&dp,int k)
{
    for(int i=30;i>=0;i--)
    {
        if((k&(1<<i)))
        {
            if(dp[i]<=0)
            {
                return false;
            }
        }
        else
        {
            if(dp[i]>0)
            {
                return true;
            }
        }
    }
    return true;
}
class Solution 
{
public:
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int n=nums.size();

        int left=0;
        map<int,int>dp;
        int ans=n+2;
        for(int right=0;right<n;right++)
        {
            int val=nums[right];
            for(int j=0;j<=30;j++)
            {
                if((val&(1<<j)))
                {
                    dp[j]++;
                }
            }

            while(check(dp,k) && left<=right)
            {
                ans=min(ans,right-left+1);
                int val=nums[left];
                for(int j=0;j<=30;j++)
                {
                    if((val&(1<<j)))
                    {
                        dp[j]--;
                    }
                }
                left++;
            }
        }

        if(ans==n+2)
        {
            ans=-1;
        }
        return ans;
    }
};
