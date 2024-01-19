class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        if(num1=="0" || num2=="0")
        {
            return "0";
        }
        int n1=num1.size();
        int n2=num2.size();
        
        vector<int>dp(n1+n2+10,0);
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                int a=num1[i]-'0';
                int b=num2[j]-'0';
                
                dp[n1-i-1+n2-1-j]+=a*b;
                
            }
        }
        
        string ans="";
        for(int i=0;i<=n1+n2+5;i++)
        {
            ans.push_back((dp[i]%10)+'0');
            dp[i+1]+=dp[i]/10;
        }
        while(ans.back()=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
