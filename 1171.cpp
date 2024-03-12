/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        vector<int>vec;
        while(head!=NULL)
        {
            vec.push_back(head->val);
            head=head->next;
        }
        
        while(true)
        {
            int n=vec.size();
            map<int,int>mp;
            int tot=0;
            bool g=false;
            mp[0]=-1;
            for(int i=0;i<n;i++)
            {
                tot+=vec[i];
                if(mp.find(tot)==mp.end())
                {
                    mp[tot]=i;
                }
                else
                {
                    int prev=mp[tot]+1;
                    int curr=i;
                    int j=0;
                    vector<int>nv;
                    while(j<n)
                    {
                        if(j<prev || j>curr)
                        {
                            nv.push_back(vec[j]);
                        }
                        j++;
                    }
                    vec=nv;
                    g=true;
                    break;
                }
            }
            if(g==false)
            {
                break;
            }
        }
        ListNode *ls=new ListNode();
        ListNode *ptr=ls;
        int n=vec.size();
        if(n==0)
        {
            return NULL;
        }
        for(int i=0;i<n;i++)
        {
            ptr->val=vec[i];
            if(i!=n-1)
            {
                ptr->next=new ListNode();
                ptr=ptr->next;
            }
            
        }
        return ls;
    }
};
