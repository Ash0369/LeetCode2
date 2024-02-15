int cd(int num)
{
    int p=num;
    int ans=0;
        
    while(p>0)
    {
        int b=p%10;
        if(b!=0 && num%b==0)
        {
            ans++;
        }
        p=p/10;
    }
    return ans;
}
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) 
    {
        vector<int>ans;
        for(int i=left;i<=right;i++)
        {
            string s=to_string(i);
            if(s.size()==cd(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
