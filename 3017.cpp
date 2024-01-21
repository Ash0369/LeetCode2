#define ll long long
class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        vector<ll int>ans(n+1,0);
        if(x>y)
        {
            swap(x,y);
        }
        for(int i=1;i<=n;i++)
        {
            ans[i]=(n-i)*2LL;
        }
        if(abs(x-y)<=1)
        {
            reverse(ans.begin(),ans.end());
            ans.pop_back();
            reverse(ans.begin(),ans.end());
            return ans;
        }
        vector<ll int>dp(n+2,0);
        vector<ll int>dpq(n+2,0);
        int d=0;
        for(int i=x;i>=1;i--)
        {
            dp[y-x+d]+=2;
            dp[n-x+d+1]-=2;
            
            dpq[d+1]+=2;
            dpq[n-y+2+d]-=2;
            d++;
        }
        ll int curr=0;
        ll int curr2=0;
        for(int i=1;i<=n;i++)
        {
            curr+=dp[i];
            curr2+=dpq[i];
            ans[i]-=curr;
            ans[i]+=curr2;
        }
        vector<ll int>dp2(n+2,0);
        vector<ll int>dp2q(n+2,0);
        for(int i=x+1;i<y;i++)
        {
            int d=i-x;
            int p=y-i;
            
            if(d<=p)
            {
                int to_r=d+1;
                if(to_r<(p))
                {
                    dp2[p]+=2;
                    dp2[n-i+1]-=2;
                    
                    dp2q[to_r]+=2;
                    dp2q[n-y+to_r+1]-=2;
                    int k=(y+x-1-i-i)/(2LL);
                    if(k>0)
                    {
                        dp2[y-i]-=2;
                        dp2[y-k-i]+=2;
                        
                        dp2q[i-x+2]+=2;
                        dp2q[i-x+2+k]-=2;
                    }
                }
            }
            else
            {
                int to_r=p+1;
                if(to_r<(d))
                {
                    dp2[d]+=2;
                    dp2[i]-=2;
                    
                    dp2q[to_r]+=2;
                    dp2q[x+to_r]-=2;
                }
            }
        }
        curr=0;
        curr2=0;
        for(int i=1;i<=n;i++)
        {
            curr+=dp2[i];
            curr2+=dp2q[i];
            
            ans[i]-=curr;
            ans[i]+=curr2;
        }
        reverse(ans.begin(),ans.end());
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
