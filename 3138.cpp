class Solution {
public:
    int minAnagramLength(string s) {
        
        int n=s.size();
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
            {
                v.push_back(i);
            }
        }
        int left=0;
        int right=v.size();
        int ans=n;
        
        while(left<v.size())
        {
            int mid=left;
            int sz=v[mid];
            map<char,int>mp;
            for(int i=0;i<sz;i++)
            {
                mp[s[i]]++;
            }
            bool res=true;
            for(int j=sz;j<n;j+=sz)
            {
                map<char,int>t=mp;
                for(int k=j;k<j+sz;k++)
                {
                    t[s[k]]--;
                }
                for(auto x:t)
                {
                    if(x.second>0 || x.second<0)
                    {
                        res=false;
                        break;
                    }
                }
            }
            if(res)
            {
                ans=sz;
                break;
            }
            left++;
        }
        return ans;
    }
};
