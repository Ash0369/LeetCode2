class Solution 
{
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n=profit.size();
        vector<vector<int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(vec.begin(),vec.end());
        
        int dp[n+10];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            //If i choose to do ith job
            int start=vec[i][0];
            int end=vec[i][1];
            int gain=vec[i][2];
           
            vector<int>v={end,-1,-1};
            auto nx=lower_bound(vec.begin(),vec.end(),v);
            int index=nx-vec.begin();
            
            dp[i]=gain+dp[index];
            dp[i]=max(dp[i],ans);
            ans=max(ans,dp[i]);
            
        }
        return ans;
    }
};
