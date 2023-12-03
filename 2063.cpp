#define ll long long
bool check(char &c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
    {
        return true;
    }
    return false;
}
class Solution 
{
public:
    long long countVowels(string word) 
    {
        int n=word.size();
        ll int ans=0;
        for(int i=0;i<n;i++)
        {
            if(check(word[i]))
            {
                ans++;
                int left=i;
                int right=n-i-1;
                ans+=left;
                ans+=right;
                ans+=(1LL*left*right);
            }
        }
        return ans;
    }
};
