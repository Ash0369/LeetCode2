class Solution 
{
public:
    int minPatches(vector<int>&coins,int target) 
    {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        int ans=0;
        long long int reachable=0;
        for(int i=0;i<n;i++)
        {
            if(coins[i]>target)
            {
                continue;
            }
            while(coins[i]-1>reachable)
            {
                ans++;
                reachable=(2*reachable)+1;
            }
            reachable+=coins[i];
        }
        while(target>reachable)
        {
            ans++;
            reachable=(2*reachable)+1;
        }
        return ans;
    }
};
