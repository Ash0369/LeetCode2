class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        int z=0;
        vector<int>ans;
        int n=nums.size();
        for(auto x:nums)
        {
            z=max(z,(int)x.size());
        }
        map<int,int>next;
        map<int,int>prev;
        for(int i=n-1;i>=0;i--)
        {
            next[i]=i-1;
            prev[i]=i+1;
        }
        for(int i=0;i<n;i++)
        {
            int p=0;
            for(int j=i;j>=0;j=next[j])
            {
                p=i-j;
                if(nums[j].size()>p)
                {
                    ans.push_back(nums[j][p]);
                }
                else{
                    next[prev[j]]=next[j];
                    prev[next[j]]=prev[j];
                }
                
            }
            
            if(i==n-1)
            {
                int start=1;
                while(start<z)
                {
                    p=start;
                    for(int j=i;j>=0;j=next[j])
                    {
                        p=start+(i-j);
                        if(nums[j].size()>p)
                        {
                            ans.push_back(nums[j][p]);
                        }
                        else
                        {
                            next[prev[j]]=next[j];
                            prev[next[j]]=prev[j];
                        }
                    }
                    start++;
                }
            }
        }
        return ans;
    }
};
