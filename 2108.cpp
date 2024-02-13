class Solution 
{
public:
    string firstPalindrome(vector<string>& words) 
    {
        for(auto x:words)
        {
            string s=x;
            reverse(s.begin(),s.end());
            if(s==x)
            {
                return x;
            }
        }
        return "";
    }
};
