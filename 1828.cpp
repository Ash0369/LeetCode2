class Solution 
{
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
    {
        vector<int>ans;
        for(auto z:queries)
        {
            int x=z[0];
            int y=z[1];
            int cnt=0;
            for(auto h:points)
            {
                int x1=h[0];
                int y1=h[1];
                
                int val=(abs(x-x1)*abs(x-x1));
                val+=abs(y-y1)*abs(y-y1);
                
                if(val<=(z[2]*z[2]))
                {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
