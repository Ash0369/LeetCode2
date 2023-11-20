class Solution 
{
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        int ans=0;
        int till1=0;
        int till2=0;
        int till3=0;
        travel.push_back(-1);
        int n=travel.size();
        for(int i=0;i<n;i++)
        {
            bool g1=false;
            bool g2=false;
            bool g3=false;
            for(auto x:garbage[i])
            {
                if(x=='P')
                {
                    g1=true;
                    ans++;
                }
                if(x=='G')
                {
                    g2=true;
                    ans++;
                }
                if(x=='M')
                {
                    g3=true;
                    ans++;
                }
            }
            if(g1)
            {
                ans+=till1;
                till1=0;
            }
            if(g2)
            {
                ans+=till2;
                till2=0;
            }
            if(g3)
            {
                ans+=till3;
                till3=0;
            }
            till1+=travel[i];
            till2+=travel[i];
            till3+=travel[i];
        }
        return ans;
    }
};
