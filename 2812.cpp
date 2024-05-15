int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool dfs(int x,int y,int n,int m,int lim,vector<vector<int>>&dp,vector<vector<int>>&vis){
    if(dp[x][y]<lim)
    {
        return false;
    }
    vis[x][y]=1;
    bool ans=false;
    if(x==n-1 && y==m-1){
        return true;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx>=0 && ny>=0 && nx<n && ny<m){
            if(vis[nx][ny]==1){
                continue;
            }
            if(dp[nx][ny]>=lim){
                ans=ans|dfs(nx,ny,n,m,lim,dp,vis);
            }
        }
    }
    return ans;
}
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dp[i][j]=0;
                    st.insert({0,i,j});
                }
            }
        }
        
        while(st.size()>0){
            auto node=(*st.begin());
            st.erase(node);
            
            int val=node[0];
            int x=node[1];
            int y=node[2];
           
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    if(dp[nx][ny]>val+1){
                        if(st.find({dp[nx][ny],nx,ny})!=st.end()){
                            st.erase({dp[nx][ny],nx,ny});
                        }
                        dp[nx][ny]=val+1;
                        st.insert({val+1,nx,ny});
                    }
                }   
            }
        }    
        int left=0;
        int right=n+m+100;
        int ans=0;
        
        while(left<=right){
            int mid=(left+right)/2;
            
            //Can i reach 
            vector<vector<int>>vis(n,vector<int>(m,0));
            bool ans1=dfs(0,0,n,m,mid,dp,vis);
            
            if(ans1){
                left=mid+1;
                ans=mid;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};
