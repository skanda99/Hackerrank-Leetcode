
// problem: "https://leetcode.com/problems/add-one-row-to-tree/"

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
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        
        if(d == 1 && root == NULL) {
            return new TreeNode(v);
        }
        else if(d == 1) {
            return new TreeNode(v, root, NULL);
        }
        
        return insertOneRow(root,  v,  d, 1);
    }
    
    TreeNode* insertOneRow(TreeNode *root, int v, int D, int d) {
        
        if(root == NULL) {
            return root;
        }
        
        if(d == D-1) {
            root->left = new TreeNode(v, root->left, NULL);
            root->right = new TreeNode(v, NULL, root->right);
            return root;
        }
        
        root->left = insertOneRow(root->left, v, D, d+1);
        root->right = insertOneRow(root->right, v, D, d+1);
        
        return root;
    }
};
