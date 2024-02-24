class Solution 
{
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        map<string,int>left;
        map<string,int>right;
        
        for(auto x:arr1)
        {
            string s=to_string(x);
            int sz=s.size();
            string p="";
            for(int i=0;i<sz;i++)
            {
                p.push_back(s[i]);
                left[p]++;
            }
        }
        
        for(auto x:arr2)
        {
            string s=to_string(x);
            int sz=s.size();
            string p="";
            for(int i=0;i<sz;i++)
            {
                p.push_back(s[i]);
                right[p]++;
            }
        }
        int sz=0;
        for(auto x:left)
        {
            if(right.find(x.first)!=right.end())
            {
                sz=max(sz,(int)x.first.size());
            }
        }
        return sz;
    }
};
