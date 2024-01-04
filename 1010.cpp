class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
     map<int,int>mp;
        int ans=0;
        for(auto x:time)
        {
            int z=x%60;
            if(z>0)
            {
                int need=60-z;
                ans+=mp[need];
            }
            else{
                int need=0;
                ans+=mp[need];
            }
            mp[z]++;
        }
        return ans;
    }
};
