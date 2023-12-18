#define ll long long
bool check(int len,vector<int>&nums,ll int k)
{
    int n=nums.size();
    
    vector<ll int>prefix(n+10,0);
    prefix[1]=nums[0];
    
    for(int i=2;i<=n;i++)
    {
        prefix[i]=prefix[i-1]+nums[i-1];
    }
    int l=1;
    for(int r=len;r<=n;r++)
    {
        ll int median=(l+r)/2;
        ll int val=nums[median-1];
        
        ll int less_to_median=((median-l+1)*val)-(prefix[median]-prefix[l-1]);
        
        ll int more_to_median=(prefix[r]-prefix[median])-((r-median)*val);
        more_to_median=max(more_to_median,0LL);
        
        if((less_to_median+more_to_median)<=k)
        {
            return true;
        }
        l++;
    }
    return false;
}
class Solution 
{
public:
    int maxFrequencyScore(vector<int>& nums, long long k) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=1;
        int right=n;
        int ans=1;
        
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(check(mid,nums,k))
            {
                ans=max(ans,mid);
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};
