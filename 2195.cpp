class Solution 
{
public:
    long long minimalKSum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        long long int tot=0;
        set<int>st;
        for(auto x:nums)
        {
            tot+=x;
            st.insert(x);
        }
        sort(nums.begin(),nums.end());
        long long int ans=(1LL*k*(k+1))/2;
        int ptr=k+1;
        
        for(int i=0;i<n;i++)
        {
            while(i+1<n && nums[i]==nums[i+1])
            {
                i++;
            }
            while(st.find(ptr)!=st.end())
            {
                ptr++;
            }
            if(nums[i]<=k)
            {
                ans+=ptr-nums[i];
                ptr++;
            }
            else{
                break;
            }
        }
        return ans;
        
    }
};
