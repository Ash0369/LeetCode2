class Solution 
{
public:
    int maxTwoEvents(vector<vector<int>>&vec) 
    {
        int n=vec.size();
     
        sort(vec.begin(),vec.end());
        
        int dp[n+10];
        memset(dp,0,sizeof(dp));
        int ans=0;
        int act=0;
        for(int i=n-1;i>=0;i--)
        {
            //If i choose to do ith job
            int start=vec[i][0];
            int end=vec[i][1];
            int gain=vec[i][2];
           
            vector<int>v={end+1,-1,-1};
            auto nx=lower_bound(vec.begin(),vec.end(),v);
            int index=nx-vec.begin();
            
            act=max(act,gain+dp[index]);
            dp[i]=max(gain,dp[i+1]);
            
        }
        return act;
    }
};
