class Solution 
{
public:
    long long largestPerimeter(vector<int>& nums) 
    {
        #define ll long long
        sort(nums.begin(),nums.end());
        int n=nums.size();
        ll int g=0;
        ll int ans=-1;
        for(int i=0;i<n;i++)
        {
            
            if(i>=2)
            {
                if(nums[i]<g)
                {
                    ans=g+nums[i];
                }
            }
            g+=nums[i];
            
        }
        return ans;
    }
};
