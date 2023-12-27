class Solution 
{
public:
    bool canConvertString(string s, string t, int k) 
    {
        int n=s.size();
        vector<int>dp(n,0);
        if(s.size()!=t.size())
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            if(t[i]>=s[i])
            {
                dp[i]=(t[i]-s[i]);
            }
            else
            {
                dp[i]=t[i]-'a';
                dp[i]+='z'-s[i];
                dp[i]++;
            }
        }
        sort(dp.begin(),dp.end());
        
        bool res=true;
        
        for(int i=0;i<n;i++)
        {
            if(dp[i]==0)
            {
                continue;
            }
            //cout<<dp[i]<<endl;
            int z=1;
            i++;
            while(i<n && dp[i]==dp[i-1])
            {
                z++;
                i++;
            }
            i--;
            
            if(k>=(dp[i]+((z-1)*26)))
            {
                
            }
            else
            {
                res=false;
                break;
            }
        }
        return res;
    }
};
