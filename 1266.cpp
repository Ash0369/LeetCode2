class Solution 
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int ans=0;
        int n=points.size();
        for(int i=0;i<n-1;i++)
        {
            //Time to visit i+1;
            
            int destx=points[i+1][0];
            int desty=points[i+1][1];
            
            int currx=points[i][0];
            int curry=points[i][1];
            
            ans+=min(abs(currx-destx),abs(curry-desty));
            ans+=max(abs(currx-destx),abs(curry-desty))-min(abs(currx-destx),abs(curry-desty));
        }
        return ans;
    }
};
