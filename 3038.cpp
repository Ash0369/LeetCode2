class Solution 
{
public:
    int maxOperations(vector<int>& nums) 
    {
        int op=0;
        int n=nums.size();
        
        for(int i=0;i+1<n;i=i+2)
        {
            int s=nums[i]+nums[i+1];
            if(i==0 || s==(nums[i-1]+nums[i-2]))
            {
                op++;
            }
            else{
                break;
            }
        }
        return op;
    }
};
