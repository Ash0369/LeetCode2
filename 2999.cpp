#define ll long long
ll int dp[30][3];
ll int dfs(int index,bool tight,string &upper,int limit,string &s)
{
   
    if(dp[index][tight]!=-1)
    {
        return dp[index][tight];
    }
    int sz=s.size();
    int need=upper.size();
    if(index+sz>need)
    {
        return 0;
    }
    if(index+sz==need)
    {
        if(tight==false)
        {
            return dp[index][tight]=1;
        }
        else
        {
            int p=0;
            int origh=index;
            while(index<need)
            {
                if((s[p]-'0')>(upper[index]-'0'))
                {
                    return dp[index][tight]=0;
                }
                else if((s[p]-'0')==(upper[index]-'0'))
                {
                    
                }
                else{
                    break;
                }
                index++;
                p++;
            }
            return dp[origh][tight]=1;
        }
    }
    ll int ans=0;
    for(int i=0;i<=limit;i++)
    {
        if(tight==true && (i==(upper[index]-'0')))
        {
            ans+=dfs(index+1,true,upper,limit,s);
        }
        else if(tight==true && (i<(upper[index]-'0')))
        {
            ans+=dfs(index+1,false,upper,limit,s);
        }
        else if(tight==false)
        {
            ans+=dfs(index+1,false,upper,limit,s);
        }
    }
    return dp[index][tight]=ans;
}
class Solution 
{
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) 
    {
        string u=to_string(finish);
        string l=to_string(start-1);
        memset(dp,-1,sizeof(dp));
        ll int ans1=dfs(0,true,u,limit,s);
        memset(dp,-1,sizeof(dp));
        ll int ans2=dfs(0,true,l,limit,s);
        return ans1-ans2;
    }
};
