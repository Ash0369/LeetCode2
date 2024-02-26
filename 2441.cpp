class Solution 
{
public:
    int findMaxK(vector<int>& nums) 
    {
        map<int,int>mp;
        for(auto x:nums)
        {
            mp[x]=1;
        }
        sort(nums.begin(),nums.end());
        
        reverse(nums.begin(),nums.end());
        
        for(auto x:nums)
        {
            if(mp[x]==1 && mp[-1*x]==1)
            {
                return x;
            }
        }
        return -1;
    }
};
