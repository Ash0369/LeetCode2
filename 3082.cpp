#define mod 1000000007
#define ll long long
ll int pwr(ll int a,ll int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2==0)
    {
        ll int ans1=pwr(a,b/2);
        ll int ans2=(ans1*ans1)%mod;
        return ans2;
    }
    ll int ans1=pwr(a,b/2);
    ll int ans2=(ans1*ans1)%mod;
    ans2=(ans2*a)%mod;
    return ans2;
}
int dp[101][101][101];
int dfs(int index,vector<int>&nums,int k,int cnt)
{
    int n=nums.size();
    if(index==n)
    {
        if(k!=0)
        {
            return 0;
        }
        //Total we have to pick cnt elements from n elements
        int rem=n-cnt;
        return pwr(2,rem);
    }
    if(dp[index][k][cnt]!=-1)
    {
        return dp[index][k][cnt];
    }
    //Not pick
    int ans1=dfs(index+1,nums,k,cnt);
    
    //Pick
    int ans2=0;
    if(k>=nums[index])
    {
        ans2=dfs(index+1,nums,k-nums[index],cnt+1);
    }
    return dp[index][k][cnt]=(ans1+ans2)%mod;
}
class Solution 
{
public:
    int sumOfPower(vector<int>& nums, int k) 
    {
        int n=nums.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                for(int p=0;p<=n;p++)
                {
                    dp[i][j][p]=-1;
                }
            }
        }
        return dfs(0,nums,k,0);
    }
};
