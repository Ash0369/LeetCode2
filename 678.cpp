int dp[1000][1000];
int dfs(int index,int a,string &s)
{
    if(index==s.size())
    {
        return a==0;
    }
    if(a<0)
    {
        return false;
    }
    if(dp[index][a+105]!=-1)
    {
        return dp[index][a+105];
    }
    if(s[index]=='(')
    {
        return dp[index][a+105]=dfs(index+1,a+1,s);
    }
    if(s[index]==')')
    {
        return dp[index][a+105]=dfs(index+1,a-1,s);
    }
    return dp[index][a+105]=(dfs(index+1,a+1,s)|dfs(index+1,a-1,s))|dfs(index+1,a,s);
}
class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));

        return dfs(0,0,s);
    }
};
