class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        while(s.back()==' ')
        {
            s.pop_back();
        }
        int ans=0;
        while(s.size()>0 && s.back()!=' ')
        {
            ans++;
            s.pop_back();
        }
        return ans;
    }
};
