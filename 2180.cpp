class Solution 
{
public:
    int countEven(int num)
    {
        int ans=0;
        for(int i=1;i<=num;i++)
        {
            int s=0;
            string p=to_string(i);
            for(auto x:p)
            {
                s+=(x-'0');
            }
            if(s%2==0)
            {
                ans++;
            }
        }
        return ans;
    }
};
