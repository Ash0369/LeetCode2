class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int>ans;
        int i=0;
        int j=0;
        int n=nums.size();
        while(i<n && nums[i]<0)
        {
            i++;
        }
        j=i;
        i--;
        while(j<n && i>=0)
        {
            if(abs(nums[i])<abs(nums[j]))
            {
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
            else
            {
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        while(i>=0)
        {
            ans.push_back(nums[i]*nums[i]);
            i--;
        }
        while(j<n)
        {
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        return ans;
    }
};
