class Solution 
{
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        map<int,int>mp;
        int left=0;
        int right=0;
        
        int ans=0;
        int n=nums.size();
        for(;right<n;right++)
        {
            mp[nums[right]]++;
            
            while(mp[nums[right]]>k)
            {
                mp[nums[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
