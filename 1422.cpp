class Solution 
{
public:
    int maxScore(string s) 
    {
        int n=s.size();
        int o=0;
        for(auto x:s)
        {
            if(x=='1')
            {
                o++;
            }
        }
        int ans=0;
        int z=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='1')
            {
                o--;
            }
            if(s[i]=='0')
            {
                z++;
            }
            ans=max(ans,o+z);
        }
        return ans;
    }
};
