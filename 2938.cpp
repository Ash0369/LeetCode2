#define ll long long
class Solution 
{
public:
    long long minimumSteps(string s) 
    {
        int cnt=0;
        ll int sum=-1;
        
        ll int ans=0;
        
        int n=s.size();
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                //I have to transfer all sum
                if(sum!=-1)
                {
                    ans+=sum-i;
                    sum--;
                }
                
                //sum=sum-cnt;
            }
            else{
                if(sum==-1)
                {
                    sum=i;
                }
               // cnt++;
               //sum+=i;
            }
        }
        return ans;
    }
};
