class Solution 
{
public:
    int maxProductDifference(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        int a=nums[0];
        int b=nums[1];
        int c=nums.back();
        nums.pop_back();
        int d=nums.back();
        
        return (c*d)-(a*b);
    }
};
