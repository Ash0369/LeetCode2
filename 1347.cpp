class Solution 
{
public:
    int minSteps(string s, string t) 
    {
        map<char,int>a;
        map<char,int>b;
        for(auto x:s)
        {
            a[x]++;
        }
        for(auto x:t)
        {
            b[x]++;
        }
        int ans=0;
        for(char g='a';g<='z';g++)
        {
            ans+=abs(a[g]-b[g]);
        }
        return ans/2;
    }
};
