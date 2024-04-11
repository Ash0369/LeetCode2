class Solution
{
public:
    string removeKdigits(string num, int k) 
    {
        stack<char>st;
        for(auto x:num)
        {
            while(st.size()>0 && st.top()>x)
            {
                if(k==0)
                {
                    break;
                }
                k--;
                st.pop();
            }
            st.push(x);
        }
        while(k>0 && st.size()>0)
        {
            k--;
            st.pop();
        }
        string ans="";
        while(st.size()>0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()>0 && ans.back()=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0)
        {
            ans.push_back('0');
        }
        return ans;
    }
};
