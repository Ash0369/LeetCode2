class Solution 
{
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) 
    {
        sort(capacity.begin(),capacity.end());
        int c=0;
        for(auto x:apple)c+=x;
        
        int ans=0;
        while(c>0)
        {
            ans++;
            c=c-capacity.back();
            capacity.pop_back();
        }
        return ans;
    }
};
