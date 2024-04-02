vector<int> dfs(multiset<vector<int>>&s,multiset<vector<int>>&d)
{
    int d1=0;
    int d2=0;

    if(s.size()>0)
    {
        d1=(*s.rbegin())[0]-(*s.begin())[0];
    }
    if(d.size()>0)
    {
        d2=(*d.rbegin())[0]-(*d.begin())[0];
    }
    if(d1>=d2)
    {
        return {(*s.rbegin())[1],(*s.begin())[1]};
    }
    return {(*d.rbegin())[1],(*d.begin())[1]};
}
int dfs2(multiset<vector<int>>&s,multiset<vector<int>>&d)
{
    int d1=0;
    int d2=0;

    if(s.size()>0)
    {
        d1=(*s.rbegin())[0]-(*s.begin())[0];
    }
    if(d.size()>0)
    {
        d2=(*d.rbegin())[0]-(*d.begin())[0];
    }
    if(d1>=d2)
    {
        return d1;
    }
    return d2;
}
class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n=points.size();
        multiset<vector<int>>s;
        multiset<vector<int>>d;

        for(int i=0;i<n;i++)
        {
            s.insert({points[i][0]+points[i][1],i});
            d.insert({points[i][0]-points[i][1],i});
        }

        vector<int>c=dfs(s,d);
        int i=c[0];

        s.erase(s.find({points[i][0]+points[i][1],i}));
        d.erase(d.find({points[i][0]-points[i][1],i}));


        int mx1=dfs2(s,d);

        s.insert({points[i][0]+points[i][1],i});
        d.insert({points[i][0]-points[i][1],i});

        
        s.insert({points[i][0]+points[i][1],i});
        d.insert({points[i][0]-points[i][1],i});
            

        i=c[1];
        s.erase(s.find({points[i][0]+points[i][1],i}));
        d.erase(d.find({points[i][0]-points[i][1],i}));

        int mx2=dfs2(s,d);


        return min(mx1,mx2);
    }
};
