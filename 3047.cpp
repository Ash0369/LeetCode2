#define ll long long
class Solution 
{
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) 
    {
        int n=bl.size();
        ll int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
               
                ll int lx=max(bl[i][0],bl[j][0]);
                ll int rx=min(tr[i][0],tr[j][0]);
                
                ll int ty=min(tr[i][1],tr[j][1]);
                ll int dy=max(bl[i][1],bl[j][1]);
                
                if(lx>rx || dy>ty)
                {
                    continue;
                }
                ll int z=min(abs(lx-rx),abs(ty-dy));
                ans=max(ans,z*z);
            }
        }
        return ans;
    }
};
