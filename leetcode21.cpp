
// problem: "https://leetcode.com/problems/merge-two-sorted-lists/"


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *FinalList=NULL,*p=NULL;
        int x;

        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val > l2->val)
            {
                x = l2->val;
                l2 = l2->next;
            }
            else
            {
                x = l1->val;
                l1 = l1->next;
            }

            ListNode *ptr = new ListNode(x);

            if(FinalList == NULL)
                FinalList = p = ptr;
            else
            {
                p->next = ptr;
                p = ptr;
            }
        }

        while(l1!=NULL)
        {
            x = l1->val;
            l1 = l1->next;

            ListNode *ptr = new ListNode(x);

            if(FinalList == NULL)
                FinalList = p = ptr;
            else
            {
                p->next = ptr;
                p = ptr;
            }
        }

        while(l2!=NULL)
        {
            x = l2->val;
            l2 = l2->next;

            ListNode *ptr = new ListNode(x);

            if(FinalList == NULL)
                FinalList = p = ptr;
            else
            {
                p->next = ptr;
                p = ptr;
            }
        }

        return FinalList;
    }
};
