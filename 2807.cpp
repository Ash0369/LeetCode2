class Solution 
{
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode* h=head;
        
        while(h!=NULL)
        {
            int val=h->val;
            
            if(h->next!=NULL)
            {
                int val2=h->next->val;
                ListNode *temp=h->next;
                ListNode *new_node=new ListNode(__gcd(val,val2));
                h->next=new_node;
                new_node->next=temp;
                h=h->next;
            }
            h=h->next;
        }
        return head;
    }
};
