class Solution 
{
public:
    int pivotInteger(int n) 
    {
        for(int i=1;i<=n;i++)
        {
            int s=(i*(i+1))/2;
            int tot=(n*(n+1))/2;
            
            int sub=(i*(i-1))/2;
            
            tot-=sub;
            
            if(s==tot)
            {
                return i;
            }
        }
        return -1;
            
                
    }
};
