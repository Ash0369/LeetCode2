bool cmp(vector<int>&vec1,vector<int>&vec2)
{
    if(vec1[0]<vec2[0])
    {
        return true;
    }
    if(vec1[0]==vec2[0])
    {
        if(vec1[1]>vec2[1])
        {
            return true;
        }
    }
    return false;
}
class Solution 
{
public:
    int numberOfPairs(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end(),cmp);
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int left=points[i][0];
            int right=points[i][1];
            set<int>st;
            for(int j=i+1;j<n;j++)
            {
                if(points[j][1]>right)
                {
                    st.insert(points[j][1]);
                    continue;
                }
                auto lb=st.lower_bound(points[j][1]);
                if(lb!=st.end() && (*lb)<=right)
                {
                        
                }
                else
                {
                    ans++;
                }
                st.insert(points[j][1]);
            }
        }
        return ans;
       
    }
};
