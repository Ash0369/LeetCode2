class Solution 
{
public:
    int findMinimumOperations(string s1, string s2, string s3) 
    {
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        
        if(min(n1,min(n2,n3))==1)
        {
            if(s1[0]==s2[0] && s2[0]==s3[0])
            {
                return n1+n2+n3-3;
            }
            return -1;
        }
        
        int cnt=0;
        for(int i=0;i<min(n1,min(n2,n3));i++)
        {
            if(s1[i]==s2[i] && s2[i]==s3[i])
            {
                cnt++;
            }
            else{
                break;
            }
        }
        if(cnt==0)
        {
            return -1;
        }
        return n1+n2+n3-(3*cnt);
    }
};
