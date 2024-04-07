class Solution 
{
public:
    string getSmallestString(string s, int k) 
    {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            for(char c='a';c<='z';c++)
            {
                char curr=s[i];
                
                int cost1=(curr-'a')-(c-'a');
                cost1=abs(cost1);
                
                int cost2=0;
                
                if(c>curr)
                {
                    cost2=26-(c-'a');
                    cost2--;
                    
                    cost2+=(curr-'a');
                    cost2++;
                }
                else
                {
                    cost2=26-(curr-'a');
                    cost2--;
                    
                    cost2+=(c-'a');
                    cost2++;
                }
                
                if(min(cost1,cost2)<=k)
                {
                    s[i]=c;
                    k-=min(cost1,cost2);
                    break;
                }
            }
        }
        return s;
    }
};
