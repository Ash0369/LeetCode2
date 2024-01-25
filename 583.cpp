class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n1=word1.size();
        int n2=word2.size();
        
        vector<vector<int>>dp(n1+2,vector<int>(n2+2,0));
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(word2[j-1]==word1[i-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        int common=dp[n1][n2];
        
        return n1-common+n2-common;
    }
};
