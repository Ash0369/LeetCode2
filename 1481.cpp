class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        map<int,int>mp;
        for(auto x:arr)
        {
            mp[x]++;
        }
        
        vector<int>vec;
        
        for(auto x:mp)
        {
            vec.push_back(x.second);
        }
        
        sort(vec.begin(),vec.end());
        
        reverse(vec.begin(),vec.end());
        
        int sz=vec.size();
        
        while(sz>0 && k>=vec.back())
        {
            k=k-vec.back();
            vec.pop_back();
            sz--;
        }
        return sz;
    }
};
