class Solution 
{
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& c) 
    {
        int n=nums.size();
        int m=c.size();
        for(int i=0;i<m;i++)
        {
            c[i]=c[i]-1;
        }
        int left=0;
        int right=m-1;
        int u=nums.size();
        int ans=-2;
        long long int tot=0;
        int z=0;
        for(auto x:nums)
        {
            if(x==0)
            {
                z++;
            }
            tot+=x;
        }
        while(left<=right)
        {
            int mid=(left+right)/2;
            vector<int>dp(n+1,0);
          
            map<int,int>mp;
            set<int>fs;
            for(int i=0;i<=mid;i++)
            {
                if(mp.find(c[i])==mp.end())
                {
                    fs.insert(i);
                }
                mp[c[i]]=1;
            }
            bool res=true;
            int extra=0;
            long long int tot2=tot;
            set<vector<int>>pq;
            for(int i=mid;i>=0;i--)
            {
               
                int index=c[i];
                if(nums[index]==0)
                {
                    extra++;
                }
                else if(fs.find(i)==fs.end())
                {
                    extra++;
                }
                else
                {
                    pq.insert({nums[index],index});
                    if(extra>0)
                    {
                        extra--;
                    }
                    else
                    {
                        auto it=*pq.begin();
                        pq.erase(it);
                        extra++;
                    }
                }
            }
            
            for(auto x:pq)
            {
                tot2-=x[0];
            }
            long long int need=tot2+n+pq.size();
            if(need<=mid+1)
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            } 
        }
        return ans+1;
    }
};
