class Solution 
{
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int j=i;
            while(i+1<n && nums[i+1]>nums[i])
            {
                i++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
