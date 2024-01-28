#define ll long long
class Solution 
{
public:
    int maximumLength(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=1;
        map<ll int,int>mp;
        for(auto x:nums)
        {
            mp[x]++;
        }
        for(int i=0;i<n;i++)
        {
            ll int ele=nums[i];
            
            int c=0;
            if(ele==1)
            {
                if(mp[1]%2==0)
                {
                    ans=max(ans,mp[1]-1);
                }
                else
                {
                    ans=max(ans,mp[1]);
                }
                
            }
            if(ele>1 && mp[ele]>1)
            {
                while(mp[ele]>1)
                {
                    c++;
                    ele=ele*ele;
                }
                if(mp[ele]==1)
                {
                    ans=max(ans,c+c+1);
                }
                else
                {
                    ans=max(ans,c+c-1);
                }
            }
            
        }
        return ans;
    }
};
