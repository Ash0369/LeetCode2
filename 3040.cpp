int dfs(int x,int y,vector<int>&nums,int s,vector<vector<int>>&dp)
{
    if(x>=y)
    {
        return 0;
    }
    int a=0;
    int b=0;
    int c=0;
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    if((nums[x]+nums[x+1])==s)
    {
        a=1+dfs(x+2,y,nums,s,dp);
    }
    if((nums[y]+nums[y-1])==s)
    {
        b=1+dfs(x,y-2,nums,s,dp);
    }
    if((nums[y]+nums[x])==s)
    {
        c=1+dfs(x+1,y-1,nums,s,dp);
    }
    return dp[x][y]=max(a,max(b,c));
}
class Solution 
{
public:
    int maxOperations(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>dp(n+10,vector<int>(n+10,-1));
        int ans1=dfs(2,n-1,nums,nums[0]+nums[1],dp);
        vector<vector<int>>dp1(n+10,vector<int>(n+10,-1));
        int ans3=dfs(0,n-3,nums,nums[n-2]+nums[n-1],dp1);
        vector<vector<int>>dp2(n+10,vector<int>(n+10,-1));
        int ans2=dfs(1,n-2,nums,nums[0]+nums[n-1],dp2);
        
        return 1+max(ans1,max(ans3,ans2));
        
    }
};
