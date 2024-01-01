class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int ans=0;
        
        int n=g.size();
        int m=s.size();
        
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(j>=m)
            {
                break;
            }
            if(s[j]>=g[i])
            {
                ans++;
                j++;
            }
            else{
                i--;
                j++;
            }
        }
        return ans;
    }
};
