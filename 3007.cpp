#define ll long long
pair<ll int,ll int>dp[100][2][10];
pair<ll int,ll int> dfs(int index,string &s,bool tight,int x)
{
    int n=s.size();
    if(index==0)
    {
        return {1,0};
    }
    if(dp[index][tight][x].first!=-1LL)
    {
        return dp[index][tight][x];
    }
    auto z=dfs(index-1,s,tight&(s[n-index]=='0'),x);
    ll int ans_cnt=z.second;
    ll int ans_occ=z.first;
    //Try to place 1
    if(tight==false || s[n-index]=='1')
    {
        if(index%x==0)
        {
            auto z1=dfs(index-1,s,tight&(s[n-index]=='1'),x);
            ans_cnt+=z1.first;
            ans_cnt+=z1.second;
            ans_occ+=z1.first;
        }
        else
        {
            auto z2=dfs(index-1,s,tight&(s[n-index]=='1'),x);
            ans_cnt+=z2.second;
            ans_occ+=z2.first;
        }
    }
    return dp[index][tight][x]={ans_occ,ans_cnt};
}
ll int f(ll int mid,int x)
{
    string s;
    while(mid>0)
    {
        if(mid&1LL)
        {
            s.push_back('1');
        }
        else
        {
            s.push_back('0');
        }
        mid=mid/2;
    }
    reverse(s.begin(),s.end());
    int n=s.size();
    for(int i=0;i<n+2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<=x;k++)
            {
                dp[i][j][k]={-1LL,-1LL};
            }
        }
    }
    ll int p=0;
    p=dfs(n,s,true,x).second;
    return p;
}
class Solution 
{
public:
    long long findMaximumNumber(long long k, int x) 
    {
        ll int left=0;
        ll int right=1e16;
        
        ll int ans=0;
        
        while(left<=right)
        {
            ll int mid=(left+right)/2;
            if(f(mid,x)<=k)
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return ans;
    }
};
