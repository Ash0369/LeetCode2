class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        sort(citations.begin(),citations.end());
        int n=citations.size();
        int left=0;
        int right=n;
        
        int ans=0;
        
        while(left<=right)
        {
            int mid=(left+right)/2;
            int f=0;
            for(auto x:citations)
            {
                if(x>=mid)
                {
                    f++;
                }
            }
            if(f>=mid)
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return ans;
    }
};
