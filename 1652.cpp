class Solution 
{
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        vector<int>dp;
        int n=code.size();
        for(int i=0;i<n;i++)
        {
            if(k>0)
            {
                int s=0;
                int j=i+1;
                int t=k;
                while(t--)
                {
                    j=j%n;
                    s+=code[j];
                    j++;
                }
                dp.push_back(s);
            }
            else if(k<0)
            {
                int s=0;
                int j=i-1;
                int t=-1*k;
                while(t--)
                {
                    if(j<0)
                    {
                        j=n-1;
                    }
                    s+=code[j];
                    j--;
                }
                dp.push_back(s);
            }
            else{
                dp.push_back(0);
            }
        }
        return dp;
    }
};
