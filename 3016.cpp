class Solution {
public:
    int minimumPushes(string word) {
         vector<int>f(26,0);
        for(auto x:word)
        {
            f[x-'a']++;
        }
        sort(f.begin(),f.end());
        int ans=0;
        reverse(f.begin(),f.end());
        for(int i=0;i<8;i++)
        {
            ans+=f[i];
        }
        for(int i=8;i<16;i++)
        {
            ans+=2*f[i];
        }
        for(int i=16;i<24;i++)
        {
            ans+=3*f[i];
        }
        for(int i=24;i<26;i++)
        {
            ans+=4*f[i];
        }
        return ans;
        
    }
};
