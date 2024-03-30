class Solution 
{
public:
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int ans=n+1;
        for(int i=0;i<n;i++)
        {
            int d=0;
            for(int j=i;j<n;j++)
            {
                d=d|nums[j];
                if(d>=k)
                {
                    ans=min(ans,j-i+1);
                }
            }
        }
        if(ans==n+1)
        {
            return -1;
        }
        return ans;
    }
};
