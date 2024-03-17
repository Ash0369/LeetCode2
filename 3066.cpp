#define ll long long
class Solution 
{
public:
    int minOperations(vector<int>& nums, int k) 
    {
        multiset<ll int>st;
        for(auto x:nums)
        {
            st.insert(x);
        }
        int ans=0;
        while(st.size()>1)
        {
            if((*st.begin())<k)
            {
                ans++;
                ll int a=*st.begin();
                st.erase(st.find(a));
                ll int b=*st.begin();
                st.erase(st.find(b));
                
                ll int v=min(a,b)*2LL;
                v+=max(a,b);
                st.insert(v);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
