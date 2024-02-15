class NumArray 
{
public:
    vector<int>ps;
    NumArray(vector<int>& nums) 
    {
        int n=nums.size();
        ps.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            ps.push_back(ps.back()+nums[i]);
        }
    }
    
    int sumRange(int left, int right) 
    {
        return ps[right]-(left>0 ? ps[left-1]:0);
    }
};
