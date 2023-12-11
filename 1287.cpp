class Solution 
{
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int n=arr.size();
        if(n<=2)
        {
            return arr[0];
        }
        int limit=n/4;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1])
            {
                cnt++;
                if(cnt>limit)
                {
                    return arr[i];
                }
            }
            else{
                cnt=1;
            }
        }
        return -1;
    }
};
