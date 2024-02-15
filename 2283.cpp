class Solution 
{
public:
    bool digitCount(string num) 
    {
        map<int,int>mp;
        for(auto x:num)
        {
            mp[x-'0']++;
        }
        int n=num.size();
        for(int i=0;i<n;i++)
        {
            if((num[i]-'0')==mp[i])
            {
                
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
