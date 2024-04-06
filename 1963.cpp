class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        int a=0;
        int ans=0;
        int p=10;
        for(auto x:s)
        {
            if(x=='[')
            {
                a++;
            }
            else
            {
                a--;
            }
            if(a<0 && a<p)
            {
                ans++;
            }
            p=min(p,a);
        }

        
        return (ans+1)/2;
    }

    
};
