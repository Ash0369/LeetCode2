bool cmp(vector<int>&v1,vector<int>&v2)
{
    if(v1[2]<v2[2])
    {
        return true;
    }
    return false;
}
class Solution
{
public:
    vector<int>findAllPeople(int n,vector<vector<int>>&meetings,int firstPerson) 
    {
        //Iterate on time 
        set<int>st;
        st.insert(0);
        st.insert(firstPerson);
        sort(meetings.begin(),meetings.end(),cmp);
        
        int sz=meetings.size();
        for(int i=0;i<sz;i++)
        {
            int tme=meetings[i][2];
            //cout<<tme<<endl;
            map<int,int>degree;
            map<int,vector<int>>graph;
            
            while(i<sz && meetings[i][2]==tme)
            {
                degree[meetings[i][0]]++;
                degree[meetings[i][1]]++;
                graph[meetings[i][0]].push_back(meetings[i][1]);
                graph[meetings[i][1]].push_back(meetings[i][0]);
                i++;
            }
            i--;
            
            queue<int>q;
            
            for(auto x:graph)
            {
                if(st.find(x.first)!=st.end())
                {
                    q.push(x.first);
                }
            }
            while(!q.empty())
            {
                int ele=q.front();
                q.pop();
                for(auto x:graph[ele])
                {
                    if(st.find(x)==st.end())
                    {
                        st.insert(x);
                        q.push(x);
                    }
                }
            }
        }
        
        vector<int>ans;
        for(auto x:st)
        {
            ans.push_back(x);
        }
        return ans;
    }
};
