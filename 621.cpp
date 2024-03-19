class Solution 
{
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        map<char,int>mp;
        int tot=0;
        for(auto x:tasks)
        {
            tot++;
            mp[x]++;
        }
        priority_queue<int>pq;
        for(auto x:mp)
        {
            pq.push(x.second);
        }
        multiset<vector<int>>st;
        int t=0;
        while(tot>0)
        {
            while(st.size()>0 && (*st.begin())[0]<=t)
            {
                pq.push((*st.begin())[1]);
                st.erase(st.find(*st.begin()));
            }
            if(pq.size()==0)
            {
                t++;
                continue;
            }
            auto ele=pq.top();
            pq.pop();
            if(ele==1)
            {
                t++;
                tot--;
                continue;
            }
            else
            {
                st.insert({t+n+1,ele-1});
                t++;
                tot--;
            }
        }
        return t;
        
    }
};
