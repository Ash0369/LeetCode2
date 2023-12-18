class Solution 
{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        map<int,int>mp;
        for(auto x:arr1)
            mp[x]++;
        
        vector<int>ans;
        for(auto x:arr2)
        {
            while(mp[x]>0)
            {
                ans.push_back(x);
                mp[x]--;
            }
        }
        for(auto x:mp)
        {
            while(mp[x.first]>0)
            {
                ans.push_back(x.first);
                mp[x.first]--;
            }
        }
        return ans;
    }
};
