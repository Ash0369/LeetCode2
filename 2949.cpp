#define ll long long
bool vowel(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
    {
        return true;
    }
    return false;
}
class Solution 
{
public:
    long long beautifulSubstrings(string s, int k) 
    {
        int n=s.size();
        long long int ans=0;
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            if(vowel(s[i]))
            {
                vec.push_back(1);
            }
            else
            {
                vec.push_back(-1);
            }
        }
        map<int,vector<int>>mp;
        int curr=0;
        mp[0].push_back(-1);
        for(int i=0;i<n;i++)
        {
            curr+=vec[i];
            for(auto x:mp[curr])
            {
                int right=i;
                int left=x+1;
                ll int len=right-left+1;
                ll int z=(len/2)*(len/2);
                if(z%k==0)
                {
                    ans++;
                }
            }
            mp[curr].push_back(i);
        }
        return ans;
    }
};
