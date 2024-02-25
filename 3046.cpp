class Solution 
{
public:
    bool isPossibleToSplit(vector<int>& nums) 
    {
        map<int,int>mp;
        for(auto x:nums)
        {
            mp[x]++;
            if(mp[x]>2)
            {
                return false;
            }
        }
        return true;
    }
};
