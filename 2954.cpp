#define ll long long
int mod=1e9+7;
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
ll int inv(ll int r)
{
	if(r==1) return 1;
	return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
}
ll mod_add(ll int a,ll int b){a=a%mod;b=b%mod;return (((a+b)%mod)+mod)% mod;}
ll mod_mul(ll int a,ll int b){a=a%mod;b=b%mod;return (((a*b)% mod)+mod)%mod;}
ll mod_sub(ll int a, ll int b){a=a%mod;b=b%mod;return (((a - b)%mod)+mod)%mod;}
ll mod_div(ll a,ll b){a=a%mod;b=b%mod;return (a*inv(b))%mod;}
class factorial
{
    public:
    vector<ll int>fact;
    factorial(int n)
    {
        fact.resize(n+1,0);
        fact[0]=1;
        for(int i=1;i<=n;i++)
        {
            fact[i]=mod_mul(fact[i-1],i);
        }
    }

    ll int ncr(int n,int r)
    {
        ll int a=fact[n];
        ll int b=fact[r];
        ll int c=fact[n-r];

        c=mod_mul(c,b);
        a=mod_div(a,c);
        return a;
    }
};

class Solution 
{
public:
    int numberOfSequence(int n, vector<int>& sick) 
    {
        factorial f1(n+2);
        ll int ans=1;
        int tot=0;
        vector<int>v;
        sort(sick.begin(),sick.end());
        int j=0;
        int curr=0;
        for(int i=1;i<sick.size();i++)
        {
            int p=sick[i]-sick[i-1]-1;
            if(p>0)
            {
               
                ans=(ans*pwr(2,p-1))%mod;
                tot+=p;
                v.push_back(p);
                    
            }
        }
        if(sick[0]!=0)
        {
            int av=sick[0];
            tot+=av;
            v.push_back(av);
        }
        int sz=sick.size();
        if(sick[sz-1]!=n-1)
        {
            int av=n-sick[sz-1]-1;
            tot+=av;
            v.push_back(av);
        }

        
        ll int c=f1.fact[tot];
        for(auto x:v)
        {
            c=mod_div(c,f1.fact[x]);
        }
        ans=(ans*c)%mod;
        return ans;
    }
};
