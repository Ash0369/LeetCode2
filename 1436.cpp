class Solution 
{
public:
    string destCity(vector<vector<string>>& paths) 
    {
        set<string>st1;
        set<string>st2;
        for(auto x:paths)
        {
            st1.insert(x[0]);
            st2.insert(x[1]);
        }
        for(auto x:st2)
        {
            if(st1.find(x)==st1.end())
            {
                return x;
            }
        }
        return "get lost";
    }
};
