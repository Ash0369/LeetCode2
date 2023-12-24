class Solution 
{
public:
    int minOperations(string s) 
    {
        int ans=0;
        int c=1;
        for(auto x:s)
        {
            if(c!=(x-'0'))
            {
                ans++;
            }
            c=!c;
        }
        c=0;
        int ans2=0;
        for(auto x:s)
        {
            if(c!=(x-'0'))
            {
                ans2++;
            }
            c=!c;
        }
        return min(ans,ans2);
    }
};
