class Solution 
{
public:
    int longestMonotonicSubarray(vector<int>&vec) 
    {
        int ans=0;
        int n=vec.size();
        
        for(int i=0;i<n;i++)
        {
            
            for(int j=i;j<n;j++)
            {
                int a=0;
                bool res=true;
                for(int k=i;k<=j;k++)
                {
                    if(k+1<=j)
                    {
                        if(vec[k+1]>vec[k] && a==-1)
                        {
                            res=false;
                        }
                        if(vec[k+1]<vec[k] && a==1)
                        {
                            res=false;
                        }
                        if(vec[k+1]>vec[k])
                        {
                            a=1;
                        }
                        else{
                            a=-1;
                        }
                        if(vec[k]==vec[k+1])
                        {
                            res=false;
                        }
                    }
                }
                if(res)
                {
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
