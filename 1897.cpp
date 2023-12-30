class Solution 
{
public:
    bool makeEqual(vector<string>& words) 
    {
        int n=words.size();
        
        map<char,int>mp;
        for(auto x:words)
        {
            for(auto y:x)
            {
                mp[y]++;
            }
        }
        
        for(auto x:mp)
        {
            if((x.second)%n)
            {
                return false;
            }
        }
        return true;
    }
};
