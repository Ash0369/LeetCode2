class Solution 
{
public:
    int getMaximumConsecutive(vector<int>& coins) 
    {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        int ans=0;
        long long int reachable=0;
        for(int i=0;i<n;i++)
        {
            if(coins[i]-1>reachable)
            {
                break;
            }
            reachable+=coins[i];
        }
        return reachable+1;
    }
};
