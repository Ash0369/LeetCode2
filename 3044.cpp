map<int,int>mp;
void dfs(int i,int j,int nx,int ny,vector<vector<int>>&mat,string &s)
{
    if(s.size()>1)
    {
        mp[stoi(s)]++;
    }
    int m=mat.size();
    int n=mat[0].size();
    
    if(i>=m || i<0 || j<0 || j>=n)
    {
        return;
    }
    
    s.push_back(mat[i][j]+'0');
    
    i=i+nx;
    j=j+ny;
    dfs(i,j,nx,ny,mat,s);
}
class Solution
{
public:
    int mostFrequentPrime(vector<vector<int>>&mat) 
    {
        mp.clear();
        int m=mat.size();
        int n=mat[0].size();
        
        if(m==1 && n==1)
        {
            return -1;
        }
        
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               // cout<<i<<" "<<j<<endl;
                int dx[3]={-1,0,1};
                int dy[3]={-1,0,1};
                
                for(int k1=0;k1<3;k1++)
                {
                    for(int k2=0;k2<3;k2++)
                    {
                        if(k1==1 && k2==1)
                        {
                            continue;
                        }
                        string s="";
                        dfs(i,j,dx[k1],dy[k2],mat,s); 
                    }
                }
            }
        }
        
        int f=0;
        int z=-1;
        for(auto x:mp)
        {
            int num=x.first;
            bool res=true;
            for(int k=2;k*k<=num;k++)
            {
                if(num%k==0)
                {
                    res=false;
                    break;
                }
            }
            if(res==false)
            {
                continue;
            }
            if(x.second>f)
            {
                f=x.second;
                z=x.first;
            }
            else if(x.second==f && x.first>z)
            {
                f=x.second;
                z=x.first;
            }
        }
        return z;
        
    }
};
