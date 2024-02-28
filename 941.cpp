class Solution 
{
public:
    bool validMountainArray(vector<int>& arr) 
    {
        int n=arr.size();
        if(n<=2)
        {
            return false;
        }
        if(arr[1]<=arr[0])
        {
            return false;
        }
        
        if(arr[n-2]<=arr[n-1])
        {
            return false;
        }
        int c=0;
        
        for(int i=1;i<n;i++)
        {
            if(c==0 && arr[i]>arr[i-1])
            {
                
            }
            else if(c==0 && arr[i]<arr[i-1])
            {
                c=1;
            }
            else if(c==1  && arr[i]<arr[i-1])
            {
                
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
