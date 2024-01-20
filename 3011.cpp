class Solution 
{
public:
    bool canSortArray(vector<int>& nums) 
    {
        vector<int>v;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            int b=__builtin_popcount(nums[i]);
            vector<int>g;
            g.push_back(nums[i]);
            i++;
            while(i<n && __builtin_popcount(nums[i])==b)
            {
                g.push_back(nums[i]);
                i++;
            }
            sort(g.begin(),g.end());
            i--;
            for(auto x:g)
            {
                v.push_back(x);
            }

        }
        if(is_sorted(v.begin(),v.end()))
        {
            return true;
        }
        return false;
    }
};
