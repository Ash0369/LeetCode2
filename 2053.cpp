class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mp;
        for(auto x:arr)
        {
            mp[x]++;
        }
        string ans="";

        for(auto x:arr)
        {
            if(mp[x]==1)
            {
                k--;
                if(k==0)
                {
                    ans=x;
                }
            }
        }
        return ans;
    }
};
