class Solution 
{
public:
    int numberOfSubstrings(string s) 
    {
        int ans=0;
        int n=s.size();
        int a=n+1;
        int b=n+1;
        int c=n+1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                a=i;
            }
            else if(s[i]=='b')
            {
                b=i;
            }
            else
            {
                c=i;
            }
            if(c!=n+1 && b!=n+1 && a!=n+1)
            {
                ans+=1+min(a,min(b,c));
            }
        }
        return ans;
    }
};
