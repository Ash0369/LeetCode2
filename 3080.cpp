#define ll long long
class Solution 
{
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        ll int tot=0;
        for(auto x:nums)
        {
            tot+=x;
        }
        set<vector<int>>st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert({nums[i],i});
        }
        int n=nums.size();
        vector<ll int>ans;
        vector<int>dp(n+1,0);      
        for(auto x:queries)
        {
            int index=x[0];
            int k=x[1];
            
            if(dp[index]==0)
            {
                tot-=nums[index];
                dp[index]=1;
                st.erase({nums[index],index});
            }
            while(k--)
            {
                if(st.size()==0)
                {
                    break;
                }
                tot-=(*st.begin())[0];
                dp[(*st.begin())[1]]=1;
                st.erase(*st.begin());
            }
            ans.push_back(tot);
        }
        return ans;
    }
};
