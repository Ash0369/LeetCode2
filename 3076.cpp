void ad(string s,map<string,int>&mp)
{
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        string g="";
        for(int j=i;j<n;j++)
        {
            g.push_back(s[j]);
            mp[g]++;
        }
    }
}
void sb(string s,map<string,int>&mp)
{
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        string g="";
        for(int j=i;j<n;j++)
        {
            g.push_back(s[j]);
            mp[g]--;
        }
    }
}
class Solution 
{
public:
    vector<string> shortestSubstrings(vector<string>& arr) 
    {
        map<string,int>mp;
        for(auto x:arr)
        {
            ad(x,mp);
        }
        vector<string>ans;
        for(auto x:arr)
        {
            sb(x,mp);
            
            string g1="-1";
            string s=x;
            int n=s.size();
            
            for(int i=0;i<n;i++)
            {
                
                string g="";
                for(int j=i;j<n;j++)
                {
                    g.push_back(s[j]);
                    if(mp[g]==0)
                    {
                        if(g1=="-1")
                        {
                            g1=g;
                        }
                        else if(g1.size()>g.size())
                        {
                            g1=g;
                        }
                        else if(g1.size()==g.size() && g1>g)
                        {
                            g1=g;
                        }
                    }
                }
            }
            if(g1=="-1")
            {
                g1="";
            }
            ans.push_back(g1);
            ad(x,mp);
        }
        return ans;
    }
};
