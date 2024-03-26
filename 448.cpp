class Solution 
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=0 || nums[i]==(i+1))
            {
                continue;
            }
            int j=nums[i]-1;
            while(nums[j]!=(j+1))
            {
                int p=j;
                j=nums[j]-1;
                nums[p]=p+1;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=(i+1))
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
