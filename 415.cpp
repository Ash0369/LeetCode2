class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        if(num1=="0")
        {
            return num2;
        }
        if(num2=="0")
        {
            return num1;
        }
        int n1=num1.size();
        int n2=num2.size();
        
        vector<int>dp(n1+n2+5,0);
        
        int i=n1-1;
        int j=n2-1;
        int ptr=0;
        while(i>=0 && j>=0)
        {
            dp[ptr]=(num1[i]-'0')+(num2[j]-'0');
            ptr++;
            i--;
            j--;
        }
        while(i>=0)
        {
            dp[ptr]=(num1[i]-'0');
            i--;
            ptr++;
        }
        while(j>=0)
        {
            dp[ptr]=(num2[j]-'0');
            j--;
            ptr++;
        }
        
        string ans="";
        
        for(int k=0;k<=ptr;k++)
        {
            ans.push_back((dp[k]%10)+'0');
            dp[k+1]+=dp[k]/10;
        }
        while(ans.back()=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
