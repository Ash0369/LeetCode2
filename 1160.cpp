class Solution 
{
public:
    int countCharacters(vector<string>& words, string chars)
    {
        map<char,int>st;
        for(auto x:chars)
        {
            st[x]++;
        }
        int ans=0;
        for(auto x:words)
        {
            bool r=true;
            map<char,int>st1=st;
            for(auto y:x)
            {
                st1[y]--;
                if(st1[y]<0)
                {
                    r=false;
                    break;
                }
            }
            if(r)
            {
                ans+=(x.size());
            }
        }
        return ans;
    }
};
