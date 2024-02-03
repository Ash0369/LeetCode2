class Solution
{
public:
    int numberOfPairs(vector<vector<int>>& points) 
    {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int left=points[i][0];
            int right=points[i][1];
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(points[j][0]<left || points[j][1]>right)
                {
                    continue;
                }
                
                int x=points[j][0];
                int y=points[j][1];
                bool res=true;
                for(int k=0;k<n;k++)
                {
                    if(k==i || k==j)
                    {
                        continue;
                    }
                    
                    if(points[k][0]>=left && points[k][0]<=x && points[k][1]<=right && points[k][1]>=y)
                    {
                        res=false;
                        break;
                    }
                }
                if(res==true)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
