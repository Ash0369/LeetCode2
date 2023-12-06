class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int k=1;
        int o=2;
        int d=1;
        for(int i=0;i<n;i++)
        {
            ans+=k;
            k++;
            d++;
            if(d==8)
            {
                d=1;
                k=o;
                o++;
            }
        }
        return ans;
    }
};
