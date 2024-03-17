#define ll long long
class Solution 
{
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        sort(happiness.begin(),happiness.end());
        int till=0;
        ll int ans=0;
        while(k>0)
        {
            int sz=happiness.size();
            happiness[sz-1]-=till;
            ans+=max(0,happiness.back());
            happiness.pop_back();
            till++;
            k--;
        }
        return ans;
    }
};
