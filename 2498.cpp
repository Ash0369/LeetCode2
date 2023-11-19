#define ll long long

bool check(int mid,vector<int>&stones)
{
    int n=stones.size();
    vector<int>dp(n,0);
    int start=stones[0];
    for(int i=1;i<n;i++)
    {
        int p=i;
        while(i<n && stones[i]-start<=mid)
        {
            i++;
        }
        i--;
        if(i<p)
        {
            return false;
        }
        dp[i]=1;
        start=stones[i];
    }
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        while(i>=0 && dp[i]==1)
        {
            i--;
        }
        if(start-stones[i]>mid)
        {
            return false;
        }
        start=stones[i];
    }
    return true;
}
class Solution 
{
public:
    int maxJump(vector<int>& stones) 
    {
        int n=stones.size();
        
        ll int left=0;
        ll int right=1e9;
        ll int ans=right;
        while(left<=right)
        {
            ll int mid=(left+right)/2;
            
            if(check(mid,stones))
            {
                ans=mid;right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};
