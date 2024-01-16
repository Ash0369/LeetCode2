class RandomizedSet 
{
public:
    map<int,int>st;
    int index=0;
    vector<int>v;
    RandomizedSet() 
    {
        index=0;
    }
    
    bool insert(int val) 
    {
        if(st.find(val)==st.end())
        {
            v.push_back(val);
            st[val]=index;
            index++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) 
    {
        if(st.find(val)==st.end())
        {
            return false;
        }
        int ele=v.back();
        int index1=st[val];
        swap(v[index1],v[index-1]);
        v.pop_back();
        st[ele]=index1;
        st.erase(val);
        index--;
        return true;
    }
    
    int getRandom() 
    {
        return v[rand()%index];
    }
};
