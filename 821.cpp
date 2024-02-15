class Solution
{
public:
    vector<int> shortestToChar(string s, char c) 
    {
        vector<int>dp;
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==c)
            {
                dp.push_back(i);
            }
        }
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            auto lb=lower_bound(dp.begin(),dp.end(),i);
            
            int offer1=n+1;
            int offer2=n+1;
            if(lb!=dp.end())
            {
                offer1=dp[lb-dp.begin()]-i;
                offer1=abs(offer1);
            }
            if(lb!=dp.begin())
            {
                lb--;
                offer2=dp[lb-dp.begin()]-i;
                offer2=abs(offer2);
            }
            ans.push_back(min(offer1,offer2));
        }
        return ans;
    }
};
