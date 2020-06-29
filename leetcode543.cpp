
// problem: "https://leetcode.com/problems/diameter-of-binary-tree/"

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

#define Pair pair<int,int>

// first-> diameter, second-> max depth

class Solution {
public:

    int diameterOfBinaryTree(TreeNode* root) {

        Pair p = traverse(root);         // define
        return p.first;
    }

    Pair traverse(TreeNode *root)
    {
        if(root == NULL)
            return Pair(0,0);

        Pair L = traverse(root->left);
        Pair R = traverse(root->right);

        int diameter = max(max(L.first,R.first),L.second+R.second);
        int depth = max(L.second,R.second);

        return Pair(diameter,depth+1);
    }
};
