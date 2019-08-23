
// problem: "https://leetcode.com/problems/remove-nth-node-from-end-of-list/"

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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int c = 1;
        if(head == NULL)
            return head;

        ListNode *p1,*p2;
        p1 = head;

        while(c != n+1)
        {
            p1 = p1->next;
            c++;
        }

        p2 = head;

        while(p1 != NULL && p1->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        if(p1 != NULL)
            p2->next = p2->next->next;
        else
            head = p2->next;

        return head;
    }
};
