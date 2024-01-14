class Solution 
{
public:
    bool closeStrings(string word1, string word2) 
    {
        map<int,int>mp1;
        map<int,int>mp2;
        
        for(auto x:word1)
        {
            mp1[x-'a']++;
        }
        for(auto x:word2)
        {
            mp2[x-'a']++;
        }
        vector<int>v1;
        vector<int>v2;
        
        for(int i=0;i<26;i++)
        {
            if(mp1[i]==0 && mp2[i]>0)
            {
                return false;
            }
            if(mp1[i]>0 && mp2[i]==0)
            {
                return false;
            }
            v1.push_back(mp1[i]);
            v2.push_back(mp2[i]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        for(int i=0;i<26;i++)
        {
            if(v1[i]!=v2[i])
            {
                return false;
            }
        }
        return true;
    }
};
