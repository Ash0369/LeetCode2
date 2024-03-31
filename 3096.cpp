class Solution 
{
public:
    int minimumLevels(vector<int>& possible) 
    {
        int n=possible.size();
        vector<int>dp(n+1,0);

        for(int i=n-1;i>=0;i--)
        {
            if(possible[i]==1)
            {
                dp[i]=1;
            }
            else{
                dp[i]=-1;
            }
            dp[i]+=dp[i+1];
        }
        int tot=0;
        for(int i=0;i<n-1;i++)
        {
            tot+=possible[i];
            if(possible[i]==0)
            {
                tot--;
            }
            if(tot>dp[i+1])
            {
                return i+1;
            }
        }
        return -1;
    }
};
