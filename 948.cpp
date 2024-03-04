class Solution
{
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int n=tokens.size();
        int ans=0;
        sort(tokens.begin(),tokens.end());
        int left=0;
        int right=n-1;
        int y=0;
        while(left<=right)
        {
            if(power>=tokens[left])
            {
                ans++;
                power-=tokens[left];
                left++;
            }
            else
            {
                if(ans==0)
                {
                    break;
                }
                power+=tokens[right];
                right--;
                ans--;
            }
            y=max(y,ans);
        }
        return y;
    }
};
