class Solution 
{
public:
    int findMiddleIndex(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        {
            return 0;
        }
        int till=0;
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=i+1;j<n;j++)
            {
                c+=nums[j];
            }
            if(c==till)
            {
                return i;
            }
            if(i!=-1)
            {
                till+=nums[i];
            }
        }
        return -1;
    }
};
