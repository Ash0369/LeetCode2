bool check(int index,string &s)
{
    int i=0;
    int n=s.size();
    while(index<n)
    {
        if(s[i]!=s[index])
        {
            return false;
        }
        i++;
        index++;
    }
    return true;
}
class Solution 
{
public:
    int minimumTimeToInitialState(string word, int k) 
    {
        int n=word.size();
        for(int i=k;i<n;i=i+k)
        {
            if(check(i,word))
            {
                return ((i-k)/k)+1;
            }
        }
        return (n+k-1)/k;
    }
};
