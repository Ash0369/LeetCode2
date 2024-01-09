class Solution 
{
public:
    int missingInteger(vector<int>& nums) 
    {
        int s=nums[0];
        int n=nums.size();
        set<int>st;
        for(auto x:nums)
        {
            st.insert(x);
        }
        for(int i=1;i<=n;i++)
        {
            if(i==n || nums[i]!=nums[i-1]+1)
            {
                while(st.find(s)!=st.end())
                {
                    s++;
                }
                return s;
            }
            else{
                s+=nums[i];
            }
        }
        return -1;
    }
};
