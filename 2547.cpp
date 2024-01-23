#define ll long long
int dfs(int index,int prev,vector<vector<int>>&f,vector<int>&nums,int k,vector<vector<int>>&dp)
{
    int n=nums.size();
    if(index==n)
    {
       if(prev==n)
       {
           return 0;
       }
       return INT_MAX;
    }
    if(dp[index][prev]!=-1)
    {
        return dp[index][prev];
    }
    //Split or not split
    int a=dfs(index+1,prev,f,nums,k,dp);
    
    int b=k;
    int start=prev;
    b+=(index-start+1)-f[prev][index];
    b+=dfs(index+1,index+1,f,nums,k,dp);
    return dp[index][prev]=min(a,b);
}
class Solution
{
public:
    int minCost(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<vector<int>>f(n+5,vector(n+5,0));
        for(int i=0;i<n;i++)
        {
            f[i][i]=1;
            set<int>st;
            st.insert(nums[i]);
            set<int>dsc;
            
            for(int j=i+1;j<n;j++)
            {
                if(dsc.find(nums[j])!=dsc.end())
                {
                    
                }
                else if(st.find(nums[j])==st.end())
                {
                    st.insert(nums[j]);
                }
                else{
                    st.erase(nums[j]);
                    dsc.insert(nums[j]);
                }
                f[i][j]=st.size();
            }
        }
        vector<vector<int>>dp(n+5,vector<int>(n+5,-1));
        return dfs(0,0,f,nums,k,dp);
    }
};
