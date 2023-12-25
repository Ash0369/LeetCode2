int mod=1e9+7;
int decode(string &s,int index,vector<int>&dp)
{
    int n=s.size();
    if(index>=n)
        return 1;

    if(s[index]=='0')
    {
        return dp[index]=0;
    }
    else
    {
        if(dp[index]==-1)
        {
            long long int a=decode(s,index+1,dp);
            dp[index]=a;
            if(s[index]=='*')
            {
                if(index+1<n && s[index+1]!='*')
                {
                    if(s[index+1]>'6')
                    {
                        dp[index]=((9*a)+decode(s,index+2,dp))%mod;
                    }
                    else
                    {
                        dp[index]=((9LL*a)+2LL*decode(s,index+2,dp))%mod;
                    }
                }
                else if(index+1<n && s[index+1]=='*')
                {
                   
                    dp[index]=((9LL*a)+15LL*decode(s,index+2,dp))%mod;
                    
                }
                else
                {
                    dp[index]=(a*9LL)%mod;
                }
                
            }
            else{
                if(index+1<s.length())
                {
                    if(s[index]=='2' && s[index+1]=='*')
                        dp[index]= (a+(6LL*decode(s,index+2,dp)))%mod;
                    else if(s[index]=='1' && s[index+1]=='*')
                        dp[index]= (a+(9LL*decode(s,index+2,dp)))%mod;
                    else if(s[index]=='2' && s[index+1]<='6')
                        dp[index]= (a+decode(s,index+2,dp))%mod;
                    else if(s[index]=='1')
                        dp[index]= (a+decode(s,index+2,dp))%mod;
                }
                dp[index]=dp[index]%mod;
            }
            
        }
        return dp[index];
    }
}
class Solution 
{
public:
    int numDecodings(string s) 
    {
        int n=s.size();
        vector<int>dp(n+1,-1);  
        return decode(s,0,dp);
    }
};
