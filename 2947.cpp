bool vowel(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
    {
        return true;
    }
    return false;
}
class Solution 
{
public:
    int beautifulSubstrings(string s, int k) 
    {
        int n=s.size();
        long long int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int v=0;
            int c=0;
            for(int j=i;j<n;j++)
            {
                if(vowel(s[j]))
                {
                    v++;
                }
                else{
                    c++;
                }
                
                if(v==c && (1LL*v*c)%k==0)
                {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
