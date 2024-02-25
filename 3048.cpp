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
        while(left<=right)
        {
            int mid=(left+right)/2;
            
            //I have time till mid
            
            map<int,int>mp;
            for(int i=mid;i>=0;i--)
            {
                if(mp.find(c[i])==mp.end())
                {
                    mp[c[i]]=i;
                }
            }
            vector<vector<int>>process;
            for(auto x:mp)
            {
                process.push_back({x.second,nums[x.first]});
            }
            if(process.size()!=u)
            {
                left=mid+1;
                continue;
            }
            sort(process.begin(),process.end());
            int ptr=0;
            int mark=0;
            bool res=true;
            int sz=process.size();
            while(ptr<sz && process[ptr][1]==0)
            {
                ptr++;
            }
            for(int i=0;i<=mid;i++)
            {
                if(mark<sz && i==(process[mark][0]))
                {
                    if(process[mark][1]==0)
                    {
                        
                    }
                    else
                    {
                        res=false;
                        break;
                    }
                    mark++;
                }
                else if(ptr<sz)
                {
                    process[ptr][1]--;
                    while(ptr<sz && process[ptr][1]==0)
                    {
                        ptr++;
                    }
                }    
            }
            if(res)
            {
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans+1;
    }
};
