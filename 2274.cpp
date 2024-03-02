class Solution 
{
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) 
    {
        sort(special.begin(),special.end());
        
        int ans=0;
        
        int prev=bottom;
        
        for(int i=0;i<special.size();i++)
        {
            int x=special[i];
            
            if(i==0)
            {
                ans=max(ans,x-bottom);
            }
            else
            {
                ans=max(ans,x-special[i-1]-1);
            }
        }
        ans=max(ans,top-special.back());
        return ans;
    }
};
