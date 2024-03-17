#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int gc(ordered_set &vec,int val)
{
    int n=vec.size();
    int p=vec.order_of_key(val+1);
    return n-p;
}
class Solution 
{
public:
    vector<int> resultArray(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>v1;
        vector<int>v2;
        
        ordered_set s1;
        ordered_set s2;
        
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        
        s1.insert(nums[0]);
        s2.insert(nums[1]);
        
        for(int i=2;i<n;i++)
        {
            int a=gc(s1,nums[i]);
            int b=gc(s2,nums[i]);
            
            cout<<a<<" "<<b<<endl;
            if(a>b)
            {
                v1.push_back(nums[i]);
                s1.insert(nums[i]);
            }
            else if(a<b)
            {
                v2.push_back(nums[i]);
                s2.insert(nums[i]);
            }
            else
            {
                int sz1=v1.size();
                int sz2=v2.size();
                
                if(sz2<sz1)
                {
                    v2.push_back(nums[i]);
                    s2.insert(nums[i]);
                }
                else
                {
                    v1.push_back(nums[i]);
                    s1.insert(nums[i]);
                }
            }
        }
        
        for(auto x:v2)
        {
            v1.push_back(x);
        }
        return v1;
    }
};
