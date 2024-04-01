int mod=1000000007;
#define ll long long
ll int dp[51][52][52][2];
int dfs(int index,int last,int size,int diff,int pick,int k,vector<int>&nums)
{
    if(size==k)
    {
        if(pick)
        {
            return 1;
        }
        return 0;
    }
    if(index>=nums.size())
    {
        return 0;
    }
    if(dp[index][last+1][size][pick]!=-1)
    {
        return dp[index][last+1][size][pick];
    }
    //Pick or nor pick

    int a=dfs(index+1,last,size,diff,pick,k,nums);
    int b=0;
    if(last==-1 || nums[index]-nums[last]>=diff)
    {
        if(last!=-1 && nums[index]-nums[last]==diff)
        {
            b=dfs(index+1,index,size+1,diff,true,k,nums);
        }
        else
        {
            b=dfs(index+1,index,size+1,diff,pick,k,nums);
        }
    }
    return dp[index][last+1][size][pick]=(a+b)%mod;
}
class Solution 
{
public:
    int sumOfPowers(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<ll int >p;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                p.insert(abs(nums[i]-nums[j]));
            }
        }

        

        //Now we can take all subbarays
        ll int ans=0;
        for(int i:p)
        {
            memset(dp,-1,sizeof(dp));
            ll int a=dfs(0,-1,0,i,false,k,nums);
            a=(a*i)%mod;
            ans=(ans+a)%mod;
        }
        return ans;
    }
};
