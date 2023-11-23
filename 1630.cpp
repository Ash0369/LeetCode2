class Solution 
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        
        int sz=l.size();
        vector<bool>ans(sz);
        for(int i=0;i<sz;i++)
        {
            int left=l[i];
            int right=r[i];
            
            vector<int>st;
            for(int j=left;j<=right;j++)
            {
                st.push_back(nums[j]);
            }
            sort(st.begin(),st.end());
            int sa=st.size();
            bool res=true;
            for(int j=1;j<sa-1;j++)
            {
                if((st[j]-st[j-1])!=(st[j+1]-st[j]))
                {
                    res=false;
                    break;
                }
            }
            ans[i]=res;
        }
        return ans;
    }
};
