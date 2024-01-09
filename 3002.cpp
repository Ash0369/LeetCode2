class Solution 
{
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int>st1;
        set<int>st2;
        for(auto x:nums1)
        {
            st1.insert(x);
        }
        for(auto x:nums2)
        {
            st2.insert(x);
        }
        int n=nums1.size();
        
        int n1=st1.size();
        int n2=st2.size();
        
        nums1.clear();
        nums2.clear();
        
        if(n1>(n/2))
        {
            //cout<<n1<<endl;
           
            
                vector<int>v;
                for(auto x:st1)
                {
                    //cout<<x<<endl;
                    if(st2.find(x)!=st2.end())
                    {
                        v.push_back(x);
                    }
                }
            
                for(auto x:v)
                {
                    //cout<<"e"<<x<<endl;
                    st1.erase(x);
                    n1--;
                    if(n1==(n/2))
                    {
                        break;
                    }
                }

                cout<<n1<<endl;
                while(n1>(n/2))
                {
                    st1.erase(*st1.begin());
                    n1--;
                }
            
        }
       
        if(n2>(n/2))
        {
           // cout<<"S"<<endl;
            int r=n2-(n/2);
            
                vector<int>v;
                for(auto x:st2)
                {
                    if(st1.find(x)!=st1.end())
                    {
                       // cout<<x<<endl;
                        v.push_back(x);
                    }
                }
                for(auto x:v)
                {
                    //cout<<x<<endl;
                    st2.erase(x);
                    n2--;
                    if(n2==(n/2))
                    {
                        break;
                    }
                }
                while(n2>(n/2))
                {
                    st2.erase(*st2.begin());
                    n2--;
                }
            
        }
        set<int>ans;
        for(auto x:st1)
        {
            ans.insert(x);
        }
        for(auto x:st2)
        {
            ans.insert(x);
        }
        n=ans.size();
        return n;
    }
};
