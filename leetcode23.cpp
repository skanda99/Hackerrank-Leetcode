
// problem: "https://leetcode.com/problems/merge-k-sorted-lists/"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define Pair pair<int,ListNode*>

struct compare
{
    bool operator () (Pair p1,Pair p2)
    {
        return p1.first>p2.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i;
        priority_queue<Pair,vector<Pair>,compare>Q;
        int k = lists.size();

        for(i=0;i!=k;i++)
        {
            if(lists[i]!=NULL)
            {
                Pair p(lists[i]->val,lists[i]);
                Q.push(p);
            }
        }

        ListNode* FinalList =NULL,*p=NULL;
        while(!Q.empty())
        {
            Pair p1 = Q.top();
            Q.pop();

            ListNode* ptr = new ListNode(p1.first);

            if(FinalList == NULL)
            {
                FinalList = ptr;
                p = ptr;
            }
            else
            {
                p->next = ptr;
                p = p->next;
            }

            p1.second = p1.second->next;
            if(p1.second != NULL)
            {
                Pair p2(p1.second->val,p1.second);
                Q.push(p2);
            }
        }

        return FinalList;
    }
};
