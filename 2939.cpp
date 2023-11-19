#define ll long long
#define mod 1000000007
class Solution 
{
public:
    int maximumXorProduct(long long a, long long b, int n) 
    {
        ll int r1=0;
        ll int r2=0;
        //int last=-1;
        int cnt=0;
        vector<int>last;
        for(int i=0;i<n;i++)
        {
            ll int b1=(a&(1LL<<i));
            ll int b2=(b&(1LL<<i));
            
            if(b1>=1 && b2>=1)
            {
                //No need to set
                r1=r1|(1LL<<i);
                r2=r2|(1LL<<i);
            }
            else if(b1==0 && b2==0)
            {
                r1=r1|(1LL<<i);
                r2=r2|(1LL<<i);
            }
            else{
                // if(last==1)
                // {
                //     r2=r2|(1LL<<i);
                //     last=2;
                // }
                // else{
                    r1=r1|(1LL<<i);
                    last.push_back(i);
                    cnt++;
                //}
            }
        }
       // cout<<last<<endl;
        for(int i=n;i<=50;i++)
        {
            ll int b1=(a&(1LL<<i));
            ll int b2=(b&(1LL<<i));
            
            if(b1>=1)
            {
                r1=r1|(1LL<<i);
            }
            if(b2>=1)
            {
                r2=r2|(1LL<<i);
            }
        }
       
            //cout<<last<<" "<<r1<<" "<<r2<<endl;
            while(r2<r1 && last.size()>0)
            {
                r1=r1^(1LL<<last.back());
                r2=r2|(1LL<<last.back());
                last.pop_back();
            }
            
        
        //cout<<r1<<" "<<r2<<endl;
        return ((r1%mod)*(r2%mod))%mod;
    }
};
