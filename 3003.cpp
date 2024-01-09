#define ll long long
map<ll int,int>mp;
int dfs(int index,string &s,int k,int op,ll int v)
{
    int n=s.size();
    if(index==n)
    {
        if(v>0LL)
        {
            return 1;
        }
        return 0;
    }
    int sz=__builtin_popcountll(v);
    auto key=((1LL*index)<<27);
    key=key|(v<<1);
    key=key|(op);
    if(mp.find(key)!=mp.end())
    {
        return mp[key];
    }
    int num=(s[index]-'a');
    if((v&(1LL<<num))==0LL)
    {
        //Here also we should offer option for change
        int ans=0;
        if(op>0)
        {
            for(char z='a';z<='z';z++)
            {
                int um=(z-'a');
                if((v&(1LL<<um))==0LL)
                {
                    ll int c=0;
                    c=c|(1LL<<um);
                    if(sz==k)
                    {
                        ans=max(ans,1+dfs(index+1,s,k,0,c));
                    }
                    else
                    {
                        v=v|(1LL<<um);
                        ans=max(ans,dfs(index+1,s,k,0,v));
                        v=v^(1LL<<um);
                    }
                    
                }
                else
                {
                    ans=max(ans,dfs(index+1,s,k,0,v)); 
                }
            }
        }
        
        if(sz<k)
        {
            v=v|(1LL<<num);
            int val=dfs(index+1,s,k,op,v);
            v=v^(1LL<<num);
            return mp[key]=max(ans,val);
        }
        else
        {
            ll int c=0;
            c=c|(1LL<<num);
            int val=1+dfs(index+1,s,k,op,c);
            return mp[key]=max(ans,val);
        }
    }
    else
    {
        int ans=dfs(index+1,s,k,op,v);
        if(op>0)
        {
            //can we try to stop them
            for(char z='a';z<='z';z++)
            {
                int um=(z-'a');
                if((v&(1LL<<um))==0LL)
                {
                    ll int c=0;
                    c=c|(1LL<<um);
                    if(sz==k)
                    {
                        ans=max(ans,1+dfs(index+1,s,k,0,c));
                    }
                    else
                    {
                        v=v|(1LL<<um);
                        ans=max(ans,dfs(index+1,s,k,0,v));
                        v=v^(1LL<<um);
                    }
                    
                }
            }
        }
        return mp[key]=ans;
    }
    return 0;
    
}
class Solution 
{
public:
    int maxPartitionsAfterOperations(string s, int k) 
    {
        mp.clear();
        return dfs(0,s,k,1,0);
    }
};
