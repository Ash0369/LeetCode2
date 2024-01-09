class Solution 
{
public:
    int minimumOperationsToMakeEqual(int x, int y) 
    {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,x});
        vector<int>dp(12*max(x,y),0);
        dp[x]=1;
        while(!pq.empty())
        {
            auto ele=pq.top();
            int m=ele[1];
            int z=ele[0];
            if(m==y)
            {
                return z;
            }
            pq.pop();
            if(m%11==0 && dp[m/11]==0)
            {
                dp[m/11]=1;
                pq.push({z+1,m/11});
            }
            if(m%5==0 && dp[m/5]==0)
            {
                dp[m/5]=1;
                pq.push({z+1,m/5});
            }
            if(m-1>=1 && dp[m-1]==0)
            {
                dp[m-1]=1;
                pq.push({z+1,m-1});
            }
            if(m+1<=(11*max(x,y)) && dp[m+1]==0)
            {
                dp[m+1]=1;
                pq.push({z+1,m+1});
            }
        }
        return -1;
            
    }
};
