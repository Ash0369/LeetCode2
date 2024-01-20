class Solution 
{
public:
    int minimumArrayLength(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int c=0;
        for(auto x:nums)
        {
            if(x==nums[0])
            {
                c++;
            }
        }
        int g=nums[0];
        for(auto x:nums)
        {
            g=__gcd(g,x);
        }
        if(g<nums[0])
        {
            return 1;
        }
        return (c+1)/2;
        
    }
};
