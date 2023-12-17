#define ll long long
class Solution 
{
public:
    ll int cost(vector<int>&nums,string s)
    {
        ll int num=stoll(s);
        ll int ans=0;
        for(auto x:nums)
        {
            ans+=abs(x-num);
        }
        return ans;
    }
    bool check(ll int n)
    {
        string s=to_string(n);
        string z=s;
        reverse(z.begin(),z.end());
        return s==z;
    }
    ll int inc(ll int x)
    {
        while(check(x)==false)
        {
            x++;
        }
        return x;
    }
    ll int dec(ll int x)
    {
        while(check(x)==false)
        {
            x--;
        }
        return x;
    }
    long long minimumCost(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        ll int avg;
        int n=nums.size();
        if(n%2==0)
        {
            avg=(nums[(n/2)]+nums[(n/2)-1])/2;
        }
        else{
            avg=nums[n/2];
        }
        ll int a=inc(avg);
        ll int b=dec(avg);
        return min(cost(nums,to_string(a)),cost(nums,to_string(b)));
            
    }
};
