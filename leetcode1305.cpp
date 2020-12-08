
// problem: "https://leetcode.com/problems/all-elements-in-two-binary-search-trees/"

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>V1, V2;
        getSorted(root1, V1);
        getSorted(root2, V2);
        
        vector<int>V;
        int i,j;
        i = j = 0;
        while(i < V1.size() && j < V2.size()) {
            
            if(V1[i] <= V2[j]) {
                V.push_back(V1[i]);
                i++;
            }
            
            else {
                V.push_back(V2[j]);
                j++;
            }
        }
        
        while(i < V1.size()) {
            V.push_back(V1[i]);
            i++;
        }
        
        while(j < V2.size()) {
            V.push_back(V2[j]);
            j++;
        }
        
        return V;
    }
    
    void getSorted(TreeNode *root, vector<int>&V) {
        
        if(root != NULL) {
            getSorted(root->left, V);
            V.push_back(root->val);
            getSorted(root->right, V);
        }
        
    }
};
