
// problem: "https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>V;
    
    Solution() {
        V = vector<int>(501, -1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        findT(root, target->val);
        
        setE(root, root->val, target->val);
        
        int i;
        vector<int>nodes;
        for(i=0;i!=501;i++) {
            if(V[i] == K) {
                nodes.push_back(i);
            }
        }
        
        return nodes;
    }
    
    void setE(TreeNode *root, int p, int target) {
        if(root == NULL || root->val == target) {
            return;
        }
        
        if(V[root->val] == -1) {
            V[root->val] = V[p]+1;
        }
        
        setE(root->left, root->val, target);
        setE(root->right, root->val, target);
    }
    
    int findT(TreeNode *root, int target) {
        if(root == NULL) {
            return -1;
        }
        
        if(root->val == target) {
            setD(root, 0);
            return 0;
        }
        
        int d;
        d = findT(root->left, target);
        
        if(d != -1) {
            V[root->val] = d+1;
            return d+1;
        }
        
        d = findT(root->right, target);
        
        if(d != -1) {
            V[root->val] = d+1;
            return d+1;
        }
        
        return -1;
    }
    
    void setD(TreeNode *root, int d) {
        if(root == NULL) {
            return;
        }
        
        V[root->val] = d;
        setD(root->left, d+1);
        setD(root->right, d+1);
    }
};
