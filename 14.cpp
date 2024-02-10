class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int ans=0;
        
        int n=strs.size();
        
        while(ans<strs[0].size())
        {
            char c=strs[0][ans];
            bool res=true;
            for(int i=1;i<n;i++)
            {
                if(strs[i][ans]!=c)
                {
                    res=false;
                    break;
                }
            }
            if(res)
            {
                ans++;
            }
            else
            {
                break;
            }
        }
        return strs[0].substr(0,ans);
    }
};
