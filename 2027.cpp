class Solution {
public:
    int minimumMoves(string s) 
    {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='O')
            {
                continue;
            }
            else
            {
                ans++;
                i++;
                i++;
            }
        }
        return ans;
    }
};
