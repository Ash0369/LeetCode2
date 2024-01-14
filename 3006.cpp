class Solution 
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) 
    {
        int n=s.size();
        int m1=a.size();
        int m2=b.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(i+m1<=n)
            {
                string z1=s.substr(i,m1);
                if(z1==a)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(abs(i-j)>k)
                        {
                            continue;
                        }
                        if(j+m2>n)
                        {
                            continue;
                        }
                        string z2=s.substr(j,m2);
                        if(z2==b)
                        {
                            ans.push_back(i);
                            break;
                        }
                    }       
                    
                }
            }
        }
        return ans;
    }
};
