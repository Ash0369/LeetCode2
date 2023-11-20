class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
        map<char,char>mp;
        map<char,bool>book;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(mp.find(c)==mp.end())
            {
                if(book.find(t[i])!=book.end())
                {
                    return false;
                }
                mp[c]=t[i];
                book[t[i]]=true;
            }
            else{
                if(mp[c]!=t[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
