class Solution 
{
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) 
    {
        map<int,int>index;
        for(int i=0;i<nums.size();i++)
        {
            index[nums[i]]=i;
        }
        
        for(auto x:operations)
        {
            int nums1=x[0];
            int nums2=x[1];
            
            int index1=index[nums1];
            
            index[nums1]=-1;
            index[nums2]=index1;
            
        }
        
        int n=nums.size();
        vector<int>ans(n);
        
        for(auto x:index)
        {
            if(x.second<0)
            {
                continue;
            }
            ans[x.second]=x.first;
        }
        return ans;
    }
};
