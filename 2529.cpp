class Solution 
{
public:
    int maximumCount(vector<int>& nums) 
    {
        int a=0;
        int b=0;
        
        for(auto x:nums)
        {
            if(x>0)
            {
                a++;
            }
            if(x<0)
            {
                b++;
            }
        }
        return max(a,b);
    }
};
