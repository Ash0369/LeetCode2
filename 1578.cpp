class Solution 
{
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int ans=0;
        int n=colors.size();
        
        for(int i=0;i<n;i++)
        {
            if(i+1<n && colors[i]==colors[i+1])
            {
                vector<int>c;
                c.push_back(neededTime[i]);
                i++;
                while(i<n && colors[i]==colors[i-1])
                {
                    c.push_back(neededTime[i]);
                    i++;
                }
                i--;
                sort(c.begin(),c.end());
                for(auto x:c)
                {
                    ans+=x;
                }
                ans-=c.back();
            }
        }
        return ans;
    }
};
