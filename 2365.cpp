#define ll long long
class Solution 
{
public:
    long long taskSchedulerII(vector<int>& tasks, int space) 
    {
        int n=tasks.size();
        ll int ans=0;
        map<int,ll int>mp;
        for(int i=0;i<n;i++)
        {
            ans++;
            if(mp.find(tasks[i])==mp.end())
            {
                mp[tasks[i]]=ans;
            }
            else
            {
                if(ans<(mp[tasks[i]]+space+1))
                {
                    ans=mp[tasks[i]]+space+1;
                    mp[tasks[i]]=ans;
                }
                else{
                    mp[tasks[i]]=ans;
                }
            }
            
        }
        return ans;
    }
};
