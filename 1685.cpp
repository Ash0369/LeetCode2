#define ll long long
class Solution 
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums)
    {
        int n=nums.size();
        ll int tot=0;
        for(auto x:nums)
        {
            tot+=x;
        }
        vector<int>ans;
        ll int prev=0;
        for(int i=0;i<n;i++)
        {
            tot-=nums[i];
            ll int temp=(tot-((n-i-1)*nums[i]));
            
            temp+=((i*nums[i])-prev);
            
            ans.push_back(temp);
            
            prev+=nums[i];
        }
        return ans;
    }
};
