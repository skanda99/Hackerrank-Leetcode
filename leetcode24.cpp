
// problem: "https://leetcode.com/problems/swap-nodes-in-pairs/"

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
    ListNode* swapPairs(ListNode* A)
    {
        if(A == NULL)
            return A;

        ListNode *p1,*p2,*t,*pl,*pr;
        p1 = A;
        p2 = A->next;
        pl = NULL;


        while(p2 != NULL)
        {
            t = p2->next;
            p2->next = p1;

            if(pl == NULL)
            {
                A = p2;
            }
            else
            {
                pl->next = p2;
            }

            pl = p1;

            p1 = t;

            if(p1 != NULL)
                p2 = p1->next;
            else
                p2 = NULL;
        }

        if(pl != NULL)
            pl->next = p1;

        return A;
    }
};
