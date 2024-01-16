class RandomizedCollection
{
public:
    map<int,set<int>>st;
    int index=0;
    vector<int>v;
    RandomizedCollection() 
    {
        index=0;
    }
    
    bool insert(int val) 
    {
        if(st.find(val)==st.end() || st[val].size()==0)
        {
            v.push_back(val);
            st[val].insert(index);
            index++;
            return true;
        }
        v.push_back(val);
        st[val].insert(index);
        index++;
        return false;
    }
    
    bool remove(int val) 
    {
        if(st.find(val)==st.end() || st[val].size()==0)
        {
            return false;
        }
        int ele=v.back();
        int index1=*st[val].rbegin();
        swap(v[index1],v[index-1]);
        v.pop_back();
        st[ele].erase(*st[ele].rbegin());
        st[ele].insert(index1);
        st[val].erase(*st[val].rbegin());
        index--;
        return true;
    }
    
    int getRandom() 
    {
        return v[rand()%index];
    }
};
