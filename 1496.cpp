class Solution 
{
public:
    bool isPathCrossing(string path) 
    {
        int x=0;
        int y=0;
        set<vector<int>>st;
        st.insert({0,0});
        for(auto z:path)
        {
            if(z=='N')
            {
                x++;
            }
            if(z=='S')
            {
                x--;
            }
            if(z=='E')
            {
                y++;
            }
            if(z=='W')
            {
                y--;
            }
            if(st.find({x,y})!=st.end())
            {
                return true;
            }
            st.insert({x,y});
        }
        return false;
    }
};
