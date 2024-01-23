int dfs(int index,vector<int>&vec,int take)
{
    if(index==vec.size())
    {
        return 0;
    }
    int a=dfs(index+1,vec,take);
    int b=0;
    if((take&vec[index])==0)
    {
        int ntake=take|vec[index];
        int st=__builtin_popcount(vec[index]);
        b=st+dfs(index+1,vec,ntake);
    }
    return max(a,b);
}
class Solution 
{
public:
    int maxLength(vector<string>& arr) 
    {
        int n=arr.size();
        vector<int>vec;
        
        for(auto x:arr)
        {
            string s=x;
            int num=0;
            
            for(auto y:s)
            {
                if((num&(1LL<<(y-'a'))))
                {
                    num=0;
                    break;
                }
                num=num|(1LL<<(y-'a'));
            }
            //cout<<num<<endl;
            vec.push_back(num);
        }
        
        //now either take or not take
        
        return dfs(0,vec,0);
        
    }
};
