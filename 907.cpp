int mod=1000000007;
int dfs(vector<int>&arr,int left,int right)
{
    if(left>right)
    {
        return 0;
    }
    int index=left;
    for(int i=left;i<=right;i++)
    {
        if(arr[i]<arr[index])
        {
            index=i;
        }
    }
    int a=dfs(arr,left,index-1);
    int b=dfs(arr,index+1,right);
    int c=(index-left)*(right-index)%mod;
    c=c%mod;
    c++;
    c+=index-left;
    c+=right-index;
    c=c%mod;
    c=(1LL*c*arr[index])%mod;
    return (a+(b+c)%mod)%mod;
}
class Solution 
{
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n=arr.size();
        return dfs(arr,0,n-1);
    }
};
