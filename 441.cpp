class Solution 
{
public:
    int arrangeCoins(int n) 
    {
        int ans=1;
        for(int i=2;i<=1000000;i++)
        {
            if((1LL*i*(i+1))/2<=n)
            {
                ans=i;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
