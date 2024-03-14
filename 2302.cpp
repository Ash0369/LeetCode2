#define ll long long
class Solution 
{
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        int n=nums.size();
        ll int ans=0;
        vector<ll int>psum(n+1,0);
        for(int i=0;i<n;i++)
        {
            psum[i]=nums[i];
            if(i!=0)
            {
                psum[i]+=psum[i-1];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            int left=0;
            int right=i;
            
            int z=-1;
            
            while(left<=right)
            {
                int mid=(left+right)/2;
                
                ll int tot=psum[i];
                if(mid>0)
                {
                    tot-=psum[mid-1];
                }
                int len=i-mid+1;
                
                ll int score=1LL*len*tot;
                
                if(score<k)
                {
                    z=mid;
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            
            if(z!=-1)
            {
                //So from i it can start and end uto z
                ans+=i-z+1;
            }
        }
        return ans;
    }
};
