class Solution 
{
public:
    int returnToBoundaryCount(vector<int>& nums) 
    {
        int ans=0;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
            if(nums[i]==0)
            {
                ans++;
            }
        }
        return ans;
    }
};
