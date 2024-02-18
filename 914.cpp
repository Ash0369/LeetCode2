class Solution 
{
public:
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        map<int,int>mp;
        for(auto x:deck)
        {
            mp[x]++;
        }
        int g=-1;
        for(auto x:mp)
        {
            if(g==-1)
            {
                g=x.second;
            }
            else{
                g=__gcd(g,x.second);
            }
        }
        return g!=1;
    }
};
