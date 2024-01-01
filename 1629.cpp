class Solution 
{
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) 
    {
        char c;
        int ans=0;
        
        int n=releaseTimes.size();
        
        int last=0;
        for(int i=0;i<n;i++)
        {
            int d=releaseTimes[i]-last;
            if(ans<d)
            {
                ans=d;
                c=keysPressed[i];
            }
            else if(ans==d && keysPressed[i]>c)
            {
                c=keysPressed[i];
            }
            last=releaseTimes[i];
        }
        return c;
    }
};
