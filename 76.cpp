bool check( map<char,int>&curr, map<char,int>&dp)
{
    for(auto x:dp)
    {
        if(curr[x.first]<x.second)
        {
            return false;
        }
    }
    return true;
}
class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        int n=s.size();
        map<char,int>dp;
        for(auto x:t)
        {
            dp[x]++;
        }
        int left=0;
        int al=0;
        int ar=-1;
        map<char,int>curr;
        for(int right=0;right<n;right++)
        {
            curr[s[right]]++;
            
            while(check(curr,dp) && left<=right)
            {
                if(ar==-1 || (ar-al+1)>(right-left+1))
                {
                    al=left;
                    ar=right;
                    
                }
                curr[s[left]]--;
                left++;
            }
        }
        if(ar==-1)
        {
            return "";
        }
        return s.substr(al,ar-al+1);
    }
};
