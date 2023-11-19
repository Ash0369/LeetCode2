class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        string c="";
        for(auto x:s)
        {
            if(int(x)>=65 && int(x)<=90)
            {
                c.push_back(tolower(x));
            }
            else if(int(x)>=97 && int(x)<=122)
            {
                c.push_back(tolower(x));
            }
            else if(int(x)>=48 && int(x)<=57)
            {
                c.push_back(x);
            }
        }
        string d=c;
        reverse(d.begin(),d.end());
        return c==d;
    }
};
