class Solution 
{
public:
    string reverseStr(string s, int k) 
    {
        int n=s.size();
        for(int i=0;i<n;i=i+(2*k))
        {
           reverse(s.begin()+i,min(s.end(),s.begin()+i+k));
            
        }
        return s;
    }
};
