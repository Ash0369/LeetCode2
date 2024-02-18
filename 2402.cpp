#define ll long long
class Solution 
{
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(),meetings.end());
        set<vector<ll int>>st;
        vector<int>dp(n+10,0);
        
        int sz=meetings.size();
        set<ll int>av;
        for(int i=0;i<n;i++)
        {
            av.insert(i);
        }
        for(int i=0;i<sz;i++)
        {
            ll int st_time=meetings[i][0];
            ll int ed_time=meetings[i][1];
            
            while(st.size()>0 && (*st.begin())[0]<=st_time)
            {
                av.insert((*st.begin())[1]);
                st.erase(*st.begin());
            }
            if(av.empty())
            {
                ll int z=(*st.begin())[0];
                ll int diff=z-st_time;
                
                st_time=(*st.begin())[0];
                ed_time=st_time+(meetings[i][1]-meetings[i][0]);
                av.insert((*st.begin())[1]);
                st.erase(*st.begin());
                
            }
            ll int room=*av.begin();
            av.erase(room);
            
            st.insert({ed_time,room});
            dp[room]++;
        }
        
        ll int mx=0;
        
        for(int i=1;i<n;i++)
        {
            if(dp[i]>dp[mx])
            {
                mx=i;
            }
        }
        return mx;
    }
};
