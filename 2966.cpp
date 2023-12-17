class Solution 
{
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n%3)
        {
            return {};
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i=i+3)
        {
            int a=nums[i];
            int b=nums[i+1];
            int c=nums[i+2];
            
            if(c-a>k || b-a>k || c-b>k)
            {
                return {};
            }
            ans.push_back({a,b,c});
        }
        return ans;
    }
};
