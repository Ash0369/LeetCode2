
class Solution 
{
public:
    string minimizeStringValue(string s) 
    {
        vector<int>vec(26,0);
        int cnt=0;
        for(auto x:s)
        {
            if(x=='?')
            {
                cnt++;
            }
            else
            {
                vec[x-'a']++;
            }
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<26;i++)
        {
            pq.push({vec[i],i});
        }
        string e;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='?')
            {
                e.push_back((pq.top()[1])+'a');
                int cnt=pq.top()[0];
                pq.pop();
                pq.push({cnt+1,(e.back()-'a')*(1)});
            }
        }
        sort(e.begin(),e.end());
        reverse(e.begin(),e.end());
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='?')
            {
                s[i]=e.back();
                e.pop_back();
            }
        }
        return s;
    }
};
