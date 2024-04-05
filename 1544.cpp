class Solution 
{
public:
    string makeGood(string s) 
    {
        int n=s.size();
        string ans="";

        for(int i=0;i<n;i++)
        {
            char c=s[i];
            int d=int(c);
            if(ans.size()>0)
            {
                char cn=ans.back();
                int dn=int(cn);

                if(c>=97 && cn<97 && d-dn==32)
                {
                    ans.pop_back();
                    continue;
                }
                if(cn>=97 && c<97 && dn-d==32)
                {
                    ans.pop_back();
                    continue;
                }
            }
            ans.push_back(s[i]);
        }
        return ans;

    }
};
