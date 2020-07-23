
// problem: "https://leetcode.com/problems/rotate-list/"

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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        int n = getSize(head);
        if(n < 2) {
            return head;
        }
        
        int i;
        ListNode *p, *t1, *t2;
        p = head;
        i = 1;
        k = k%n;
        
        if(!k) {
            return head;
        }
        
        while(p != NULL) {
            if(i == n-k) {
                t1 = p;
                p = p->next;
                t2 = p;
                t1->next = NULL;
                i++;
            }
            else {
                i++;
                t1 = p;
                p = p->next;
            }
        }
        
        t1->next = head;
        head = t2;
        
        return head;
    }
    
    int getSize(ListNode *p) {
        int n = 0;
        while(p != NULL) {
            p = p->next;
            n++;
        }
        
        return n;
    }
};
