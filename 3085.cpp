class Solution 
{
public:
    int minimumDeletions(string word, int k)
    {
        map<char,int>mp;
        for(auto x:word)
        {
            mp[x]++;
        }
        vector<int>v;
        for(auto x:mp)
        {
            v.push_back(x.second);
        }
        int sz=v.size();
        sort(v.begin(),v.end());
        
        int ans=1e6;
        if(abs(v.back()-v[0])<=k)
        {
            return 0;
        }
        int path=0;
        for(int i=0;i<sz;i++)
        {
            //Try all to make 
            int cutoff=v[i]+k;
            int hand=0;
            for(int j=i+1;j<sz;j++)
            {
                if(v[j]>cutoff)
                {
                    hand+=v[j]-cutoff;
                }
            }
            ans=min(ans,hand+path);
            path+=v[i];
        }
        return ans;
    }
};
