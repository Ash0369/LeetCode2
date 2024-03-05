class Solution 
{
public:
    int minimumLength(string s) 
    {
        int n=s.size();
        int j=n-1;
        int i=0;
        for(;i<j;)
        {
            if(s[i]==s[j])
            {
                char c=s[i];
                while(i<=j && s[i]==c)
                {
                    i++;
                }
                while(j>=i && s[j]==c)
                {
                    j--;
                }
            }
            else
            {    
                break;
            }
        }
        return max(0,j-i+1);
    }
};
