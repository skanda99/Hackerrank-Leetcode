
// problem: "https://leetcode.com/problems/binary-tree-level-order-traversal/"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#define Pair pair<TreeNode*,int>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>V;
        if(root == NULL)
            return V;
        
        queue<Pair>Q;
        Q.push(Pair(root,0));
        
        int h = 0;
        deque<int>v;
        
        while(!Q.empty())
        {
            Pair p = Q.front();
            Q.pop();
            
            if(h != p.second)
            {
                V.push_back(vector<int>());
            
                while(!v.empty())
                {
                    V[h].push_back(v.front());
                    v.pop_front();
                }
    
                h = p.second;
            }
            
            v.push_back(p.first->val);
            
            if(p.first->left != NULL)
                Q.push(Pair(p.first->left,p.second+1));
            
            if(p.first->right != NULL)
                Q.push(Pair(p.first->right,p.second+1));
        }
        
        V.push_back(vector<int>());
            
        while(!v.empty())
        {
            V[h].push_back(v.front());
            v.pop_front();
        }
        
        return V;
    }
};
