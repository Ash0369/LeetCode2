class Solution 
{
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        int n=heights.size();
        int left=0;
        int right=n-1;
        
        int ans=left;
        while(left<=right)
        {
            int mid=(left+right)/2;
            
            vector<int>d;
            
            for(int i=0;i<mid;i++)
            {
                if(heights[i+1]>heights[i])
                {
                    d.push_back(heights[i+1]-heights[i]);
                }
            }
            
            sort(d.begin(),d.end());
            
            int l=ladders;
            int b=bricks;
            
            while(l--)
            {
                if(d.size()>0)
                {
                    d.pop_back();
                }
            }
            
            while(d.size()>0 && d.back()<=b)
            {
                b-=d.back();
                d.pop_back();
            }
            
            if(d.empty())
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
