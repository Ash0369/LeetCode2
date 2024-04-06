class Solution 
{
public:
    string makeFancyString(string s) 
    {
        int n=s.size();
        if(n<=2)
        {
            return s;
        }
       
        string ans="";

        int i=1;
        int j=2;
        while(j<n)
        {
            if(s[j]==s[i] && s[j]==s[i-1] && s[i]==s[i-1])
            {
                i++;
                j++;
            }
            else
            {
                ans.push_back(s[i-1]);
                i++;
                j++;
            }
        }
        ans.push_back(s[i-1]);
        ans.push_back(s[i]);
        return ans;
    }
};
