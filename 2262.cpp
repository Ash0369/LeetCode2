#define ll long long
class Solution 
{
public:
    long long appealSum(string s)
    {
        ll int ans=0;
        int n=s.size();
        vector<int>dp(26,0);
        for(int i=0;i<n;i++)
        {
            int start=dp[s[i]-'a'];
            int left=i-start;
            int right=n-i-1;
            ans+=left*right;
            ans+=i-start+1; 
            ans+=n-i;
            ans--;
            dp[s[i]-'a']=i+1;
        }
        return ans;
    }
};
