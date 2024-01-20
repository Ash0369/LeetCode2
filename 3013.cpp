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
