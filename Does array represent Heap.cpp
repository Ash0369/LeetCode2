class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        for(int i=0;i<n;i++)
        {
            int lc=0;
            int rc=0;
            
            if((2*i)+1<n)
            {
                lc=arr[(2*i)+1];
            }
            if((2*i)+2<n)
            {
                rc=arr[(2*i)+2];
            }
            if(lc>arr[i] || rc>arr[i])
            {
                return false;
            }
        }
        return true;
    }
};
