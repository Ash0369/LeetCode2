class Solution
{
public:
    int findComplement(int num)
    {
        int ans=0;
        int bit=0;
        while(num>0)
        {
            if((num&1))
            {
                
            }
            else{
                ans=ans|(1<<bit);
            }
            bit++;
            num=num/2;
        }
        return ans;
    }
};
