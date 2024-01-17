class Solution 
{
public:
    int minimumOperations(vector<int>& nums) 
    {
        map<int,int>mp1;
        map<int,int>mp2;
        
        int n=nums.size();
        int t1=0;
        int t2=0;
        for(int i=0;i<n;i=i+2)
        {
            t1++;
            mp1[nums[i]]++;
        }
        for(int i=1;i<n;i=i+2)
        {
            t2++;
            mp2[nums[i]]++;
        }
        
        vector<vector<int>>f1;
        vector<vector<int>>f2;
        
        for(auto x:mp1)
        {
            f1.push_back({x.second,x.first});
        }
        for(auto x:mp2)
        {
            f2.push_back({x.second,x.first});
        }
        f1.push_back({0,1});
        f2.push_back({0,2});
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        
        int sz1=f1.size();
        int sz2=f2.size();
        
        int ans=n;
        for(int i=sz1-1;i>=max(0,sz1-3);i--)
        {
            for(int j=sz2-1;j>=max(0,sz2-3);j--)
            {
                if(f1[i][1]!=f2[j][1])
                {
                    int op1=t1-f1[i][0];
                    int op2=t2-f2[j][0];
                    ans=min(ans,op1+op2);
                }
            }
        }
        return ans;
    }
};
