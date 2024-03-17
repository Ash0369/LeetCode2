class Solution 
{
public:
    bool isSubstringPresent(string s) 
    {
        map<string,int>mp;
        int n=s.size();
        for(int i=0;i<n-1;i++)
        {
            string g="";
            g.push_back(s[i]);
            g.push_back(s[i+1]);
            mp[g]++;
        }
        for(int i=n-1;i>=1;i--)
        {
            string g="";
            g.push_back(s[i]);
            g.push_back(s[i-1]);
            if(mp[g]>0)
            {
                return true;
            }
        }
        return false;
    }
};
