class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int>v;
        for(int i=0;i<=31;i++)
        {
            if((n&1LL))
            {
                v.push_back(1);
            }
            else{
                v.push_back(0);
            }
            n=n/2;
        }
        
        uint32_t ans=0;
        
        int bit=0;
        
        while(v.size()>0)
        {
            if(v.back()==1)
            {
                ans=ans|(1LL<<bit);
            }
            bit++;
            v.pop_back();
            
        }
        return ans;
    }
};
