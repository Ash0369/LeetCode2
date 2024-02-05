class Solution 
{
public:
    int subtractProductAndSum(int n) 
    {
        int ans=1;
        int ans1=0;
        string s=to_string(n);
        for(auto x:s)
        {
            ans=ans*(x-'0');
            ans1+=(x-'0');
        }
        return ans-ans1;
    }
};
