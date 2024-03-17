#define ll long long
class Solution 
{
public:
    long long countSubstrings(string s, char c) 
    {
        int cnt=0;
        for(auto x:s)
        {
            if(x==c)
            {
                cnt++;
            }
        }
        ll int ans=0;
        for(auto x:s)
        {
            if(x==c)
            {
                ans+=cnt;
                cnt--;
            }
        }
        return ans;
    }
    
};
