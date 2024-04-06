class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int ans=0;
        int a=0;
        for(auto x:s)
        {
            if(x=='(')
            {
                a++;
            }
            else
            {
                a--;
            }

            if(a<0)
            {
                a++;
                ans++;
            }
        }
        ans+=a;
        return ans;
    }
};
