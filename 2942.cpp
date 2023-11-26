class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int p=0;
        for(auto x1:words)
        {
            for(auto y:x1)
            {
                if(y==x)
                {
                    ans.push_back(p);
                    break;
                }
            }
            p++;
        }
        return ans;
    }
};
