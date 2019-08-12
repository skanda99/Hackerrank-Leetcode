
// problem: "https://leetcode.com/problems/add-two-numbers/"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *p=NULL,*s=NULL,*p1 = l1,*p2 = l2;
        int carry = 0;

        p = s = new ListNode(0);

        while(p1!=NULL && p2!=NULL)
        {
            int x = p1->val + p2->val + carry;
            p->val = x%10;
            carry = x/10;

            p1 = p1->next;
            p2 = p2->next;

            if(p1!=NULL || p2!=NULL)
            {
                p->next = new ListNode(0);
                p = p->next;
            }
        }


        if(p1!=NULL)
        {
            while(p1!=NULL)
            {
                int x = p1->val + carry;
                p->val = x%10;
                carry = x/10;

                p1 = p1->next;

                if(p1!=NULL)
                {
                    p->next = new ListNode(0);
                    p = p->next;
                }
            }
        }

        if(p2!=NULL)
        {
            while(p2!=NULL)
            {
                int x = p2->val + carry;
                p->val = x%10;
                carry = x/10;

                p2 = p2->next;

                if(p2!=NULL)
                {
                    p->next = new ListNode(0);
                    p = p->next;
                }
            }
        }

        if(carry!=0)
        {
            p->next = new ListNode(0);
            p = p->next;

            p->val = carry;
        }

        return s;
    }
};
