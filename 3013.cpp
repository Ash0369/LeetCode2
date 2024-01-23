//Method-1 : 

#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define pbds tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
void myerase(pbds &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    auto it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
class Solution 
{
public:
    long long minimumCost(vector<int>& nums, int k, int dist) 
    {
        pbds st;
        ll int ans=0;
        int n=nums.size();
        ll int g=0;
        for(int i=1;i<=dist+1;i++)
        {
            st.insert(nums[i]);
        }
        int j=k-1;
        for(auto x:st)
        {
            ans+=x;
            g+=x;
            j--;
            if(j==0)
            {
                break;
            }
        }
        ans+=nums[0];
        int left=1;
        for(int i=dist+2;i<n;i++)
        {
            myerase(st,nums[left]);
            int p=st.order_of_key(nums[left]);
            bool r=false;
            if(p<k-1)
            {
                r=true;
                g-=nums[left];
               
            }
            p=st.order_of_key(nums[i]);
            if(p<k-1)
            {
                if(r==false)
                {
                    g-=*st.find_by_order(k-2);
                }
                g+=nums[i];
                st.insert(nums[i]);    
            }
            else if(r==true)
            {
                st.insert(nums[i]);
                g+=*st.find_by_order(k-2);
            }
            else
            {
                st.insert(nums[i]);
            }
            ans=min(ans,nums[0]+g);
            
            left++;
        }
        return ans;
    }
};


//Method-2 : Rolling_Median

#define ll long long
class Rolling_Median
{
    public:
    multiset<ll int>left;
    multiset<ll int>right;
    ll int sum_l=0;
    ll int sum_r=0;
    ll int sz_l;
    ll int sz_r;
    ll int k;
    Rolling_Median(ll int need)
    {
        k=need;//Here k can by according to question
        sz_l=0;
        sz_r=0;
    }
    void re_balance()
    {
        while(sz_l<k && sz_r>0)
        {
            sum_l+=*right.begin();
            left.insert((*right.begin()));
            sum_r-=*right.begin();
            right.erase(right.find(*right.begin()));
            sz_l++;
            sz_r--;
        }
        while(sz_l>k)
        {
            sum_l-=*left.rbegin();
            sum_r+=*left.rbegin();
            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
            sz_l--;
            sz_r++;
        }
    }
    void insert(ll int x)
    {
        if(sz_l==0 || x<(*left.rbegin()))
        {
            sum_l+=x;
            left.insert(x);
            sz_l++;
        }
        else
        {
            sum_r+=x;
            sz_r++;
            right.insert(x);
        }
        re_balance();
    }
    void erase(ll int x)
    {
        if(left.find(x)==left.end())
        {
            right.erase(right.find(x));
            sz_r--;
            sum_r-=x;
        }
        else
        {
            left.erase(left.find(x));
            sz_l--;
            sum_l-=x;
        }
        re_balance();
    }
    ll int get_left()
    {
        return sum_l;
    }
};
class Solution 
{
public:
    long long minimumCost(vector<int>& nums, int k, int dist) 
    {
        Rolling_Median rm(k-1);
        ll int ans=1e18;
        int left=1;
        int n=nums.size();
        int curr_size=0;
        for(int i=1;i<n;i++)
        {
            rm.insert(nums[i]);
            while((i-left)>dist)
            {
                rm.erase(nums[left]);
                left++;
            }
            if((i-left+1)>=k-1)
            {
                ans=min(ans,nums[0]+rm.get_left());
            }
        }
        return ans;
    }
};
