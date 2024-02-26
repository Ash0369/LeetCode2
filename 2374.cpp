class Solution 
{
public:
    int edgeScore(vector<int>& edges) 
    {
        vector<vector<long long int>>score;
        int n=edges.size();
        vector<long long int>degree(n+2,0);
        
        for(int i=0;i<n;i++)
        {
            degree[edges[i]]+=i;
        }
        
        for(int i=0;i<n;i++)
        {
            score.push_back({degree[i],-1*i});
        }
        sort(score.begin(),score.end());
        
        return -1*score.back()[1];
    }
};
