class Solution 
{
public:
    bool isHappy(int n) 
    {
        set<int>st;
        st.insert(n);
        while(n!=1)
        {
            int s=0;
            while(n>0)
            {
                s+=(n%10)*(n%10);
                n=n/10;
            }
            n=s;
            if(s==1)
            {
                return true;
            }
            if(st.find(n)!=st.end())
            {
                return false;
            }
            st.insert(n);
        }
        return true;
    }
};
