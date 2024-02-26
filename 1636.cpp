class Solution 
{
public:
    vector<int> frequencySort(vector<int>& nums) 
    {
        int n=nums.size();
        
        map<int,int>mp;
        for(auto x:nums)
        {
            mp[x]++;
        }
        vector<vector<int>>f;
        for(auto x:mp)
        {
            f.push_back({x.second,-1*x.first});
        }
        sort(f.begin(),f.end());
        
        vector<int>ans;
        
        for(auto x:f)
        {
            int g=x[0];
            while(g--)
            {
                ans.push_back(-1*x[1]);
            }
        }
        return ans;
    }
};
