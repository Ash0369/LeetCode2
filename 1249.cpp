class Solution 
{
public:
    string minRemoveToMakeValid(string s) 
    {
        int a=0;
        string ans="";
        string temp="";

        int n=s.size();

        for(int i=0;i<n;i++)
        {
            temp.push_back(s[i]);
            if(s[i]=='(')
            {
                a++;
            }
            if(s[i]==')')
            {
                a--;
            }
            if(a<0)
            {
                temp.pop_back();
                a++;
            }
            if(a==0)
            {
                ans+=temp;
                temp.clear();
            }
        }
        if(a>0)
        {
            int b=0;
            string g="";
            string ans2="";
            while(temp.size()>0)
            {
                if(temp.back()=='(')
                {
                    b++;
                }
                else if(temp.back()==')'){
                    b--;
                }

                if(b>0)
                {
                    b--;
                    temp.pop_back();
                    continue;
                }
                g.push_back(temp.back());
                temp.pop_back();
                if(b==0)
                {
                    ans2+=g;
                    g.clear();
                }
            }
            reverse(ans2.begin(),ans2.end());
            ans+=ans2;



        }
        return ans;
    }
};
