class FindSumPairs 
{
public:
    map<int,int>mp1;
    map<int,int>mp2;
    vector<int>v1;
    vector<int>v2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        for(auto x:nums1)
        {
            mp1[x]++;
        }
        for(auto x:nums2)
        {
            mp2[x]++;
        }
        v1=nums1;
        v2=nums2;
    }
    
    void add(int index, int val) 
    {
        mp2[v2[index]]--;
        v2[index]+=val;
        mp2[v2[index]]++;
    }
    
    int count(int tot) 
    {
        int ans=0;
        for(auto x:mp1)
        {
            int need=tot-x.first;
            ans+=mp2[need]*x.second;
        }
        return ans;
    }
};
