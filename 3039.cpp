class Solution 
{
public:
    string lastNonEmptyString(string s) 
    {
        map<int,vector<int>>mp;
        
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]-'a'].push_back(i);
        }
        for(auto &x:mp)
        {
            reverse(x.second.begin(),x.second.end());
        }
        
        vector<vector<int>>last;
        
        while(mp.size()>0)
        {
            vector<vector<int>>dp;
            queue<int>q;
            for(auto &x:mp)
            {
                dp.push_back({x.second.back(),x.first});
                if(x.second.size()==1)
                {
                    q.push(x.first);
                }
                x.second.pop_back();
            }
            last=dp;
            while(!q.empty())
            {
                mp.erase(q.front());
                q.pop();
            }
        }
        sort(last.begin(),last.end());
        
        string ans="";
        for(auto x:last)
        {
            ans.push_back((x[1])+'a');
        }
        return ans;
        
    }
};
