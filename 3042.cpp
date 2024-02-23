bool suf(string &s1,string &s2)
{
    int n1=s1.size();
    int n2=s2.size();
    
    if(n1>n2)
    {
        return false;
    }
    n1--;
    n2--;
    while(n1>=0 && n2>=0)
    {
        if(s1[n1]==s2[n2])
        {
            
        }
        else
        {
            return false;
        }
        n1--;
        n2--;
    }
    return true; 
}
bool pre(string &s1,string &s2)
{
    int n1=s1.size();
    int n2=s2.size();

    
    int i=0;
    int j=0;
    while(i<n1 && j<n2)
    {
        if(s1[i]==s2[j])
        {
            
        }
        else
        {
            return false;
        }
        i++;
        j++;
    }
    return true;
}
class Solution
{
public:
    int countPrefixSuffixPairs(vector<string>& words) 
    {
        int ans=0;
        
        int n=words.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(suf(words[i],words[j])==true && pre(words[i],words[j])==true)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
