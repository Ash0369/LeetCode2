class Solution {
public:
    string getHint(string secret, string guess) {
        int a=0;
        int b=0;
        map<int,int>mp;
        for(int i=0;i<secret.size();i++)
        {
            if(guess[i]!=secret[i])
            {
                mp[secret[i]]++;
            }
        }
        for(int i=0;i<secret.size();i++)
        {
            if(guess[i]==secret[i])
            {
                a++;
            }
            else if(mp[guess[i]]){
                mp[guess[i]]--;
                b++;
            }
        }
        
        string ans="";
        ans+=to_string(a);
        ans.push_back('A');
        
        ans+=to_string(b);
        ans.push_back('B');
        
        return ans;
    }
};
