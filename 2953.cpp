bool check(vector<int>&f,int k)
{
    for(int i=0;i<26;i++)
    {
        if(f[i]>0 && f[i]!=k)
        {
            return 0;
        }
    }
    return 1;
}
int cal(string &word,int len,int k)
{
    int ans=0;
    int n=word.size();
    int left=0;
    int right=0;
    vector<int>f(26,0);
    for(int i=0;i<n;i++)
    {
        f[word[i]-'a']++;
        if(i-left+1>len)
        {
            f[word[left]-'a']--;
            left++;
        }
        int x=int(word[i]);
        if(i>0)
        {
            int y=int(word[i-1]);
            if(abs(x-y)<=2)
            {
                
            }
            else
            {
                left=i;
                for(int i=0;i<26;i++)
                {
                    f[i]=0;
                }
                f[word[i]-'a']++;
            }
        }
        if(i-left+1==len)
        {
            if(check(f,k))
            {
                ans++;
            }
        }
    }
    return ans;
}
class Solution 
{
public:
    int countCompleteSubstrings(string word, int k) 
    {
        int ans=0;
        for(int i=1;i<=26;i++)
        {
            ans+=cal(word,i*k,k);
        }
        return ans;
        
    }
};
