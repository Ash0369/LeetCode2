class Solution 
{
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        int ans=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            int tot=0;
            for(int j=i;j<n;j=j+2)
            {
                tot+=arr[j];
                if(j!=i)
                {
                    tot+=arr[j-1];
                }
                ans+=tot;
            }
        }
        return ans;
    }
};
