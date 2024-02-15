class Solution 
{
public:
    int getLucky(string s, int k) 
    {
        int p=0;
        for(auto x:s)
        {
            int d=x-'a';
            d++;
            while(d>0)
            {
                p+=d%10;
                d=d/10;
            }
        }
        k--;
        
        while(k>0)
        {
            int z=0;
            while(p>0)
            {
                z+=p%10;
                p=p/10;
            }
            p=z;
            k--;
        }
        return p;
    }
};
