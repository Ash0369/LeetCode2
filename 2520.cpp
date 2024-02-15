class Solution
{
public:
    int countDigits(int num)
    {
        int p=num;
        int ans=0;
        
        while(p>0)
        {
            int b=p%10;
            if(b!=0 && num%b==0)
            {
                ans++;
            }
            p=p/10;
        }
        return ans;
    }
};
