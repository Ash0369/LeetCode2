class Solution 
{
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int>ans;
        for(int i=1;i<=9;i++)
        {
            int num=i;
            int next_digit=i+1;
            
            while(num<=high && next_digit<=9)
            {
                num=num*10;
                num+=next_digit;
                if(low<=num && num<=high)
                {
                    ans.push_back(num);
                }
                next_digit++;
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};
