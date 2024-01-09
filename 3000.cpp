class Solution 
{
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) 
    {
        double ans=0;
        int c=0;
        for(auto x:dimensions)
        {
            int a=x[0];
            int b=x[1];
            
            double d=(a*a);
            d+=(b*b);
            d=sqrt(d);
            if(d>ans)
            {
                ans=d;
                c=(a*b);
            }
            else if(d==ans)
            {
                c=max(c,a*b);
            }
        }
        return c;
    }
};
