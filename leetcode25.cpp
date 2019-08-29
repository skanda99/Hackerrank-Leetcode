
// problem: "https://leetcode.com/problems/reverse-nodes-in-k-group/"

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
    ListNode* reverseKGroup(ListNode* H,int k)
    {
        int c;
        ListNode *p1,*p2,*p3,*l,*r,*t;

        if(H == NULL || H->next == NULL || k==1)
            return H;

        ListNode *p = new ListNode(-1);
        p->next = H;
        H = p;

        l = H;
        r = H->next;

        while(r != NULL)
        {
            c = 0;
            while(r!=NULL && c<k)
            {
                r = r->next;
                c++;
            }

            if(r == NULL && c<k)
                break;

            p1 = l;
            p2 = l->next;
            p3 = l->next->next;

            while(p3 != r)
            {
                if(p1 == l)
                    p2->next = r;
                else
                    p2->next = p1;

                p1 = p2;
                p2 = p3;
                p3 = p3->next;
            }

            if(p1 == l)
                p2->next = r;
            else
                p2->next = p1;

            t = l->next;
            l->next = p2;
            l = t;
        }

        H = H->next;

        return H;
    }
};
