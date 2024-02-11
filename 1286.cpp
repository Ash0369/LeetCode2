class CombinationIterator 
{
public:
    string s;
    int n;
    vector<string>pre;
    void generate(int index,string &curr)
    {
        if(curr.size()==n)
        {
            pre.push_back(curr);
            return;
        }
        if(index>=s.size())
        {
            return;
        }
        generate(index+1,curr);
        curr.push_back(s[index]);
        generate(index+1,curr);
        curr.pop_back();
        
    }
    CombinationIterator(string characters, int combinationLength) 
    {
        s=characters;
        n=combinationLength;
        string curr="";
        generate(0,curr);
        
        sort(pre.begin(),pre.end());
        reverse(pre.begin(),pre.end());
    }
    
    string next() 
    {
        string ans=pre.back();
        pre.pop_back();
        return ans;
    }
    
    bool hasNext() 
    {
        return pre.size()>0;
    }
};
