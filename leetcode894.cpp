
// problem: "https://leetcode.com/problems/all-possible-full-binary-trees/"

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

#define Pair pair<int, int>

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        
        vector<TreeNode*>ans;
        if(N%2 == 0) {
            return ans;
        }
        
        vector<vector<Pair>>V;
        queue<int>parent;
        parent.push(0);
        
        getTrees(parent, vector<Pair>(N, {-1, -1}), V, N-1);
        ac
        // build trees
        // yet to complete
        // check
//         int i, j;
//         for(i=0;i!=V.size();i++) {
//             for(j=0;j!=V[i].size();j++) {
//                 cout<<j<<": "<<V[i][j].first<<" "<<V[i][j].second<<'\n';
//             }
            
//             cout<<'\n';
//         }
        
        int i;
        for(i=0;i!=V.size();i++) {
            TreeNode *pt = new TreeNode();
            buildTree(pt, 0, V[i]);
            ans.push_back(pt);
        }
        
        return ans;
    }
    
    void buildTree(TreeNode *pt, int p, vector<Pair>&v) {
        
        if(v[p].first == -1) {
            return;
        }
        
        pt->left = new TreeNode();
        pt->right = new TreeNode();
        
        buildTree(pt->left, v[p].first, v);
        buildTree(pt->right, v[p].second, v);
    }
    
    void getTrees(queue<int>parent, vector<Pair>v, vector<vector<Pair>>&V, int n) {
        if(n == 0) {
            V.push_back(v);
            return;
        }
        
        if(parent.empty()) {
            return;
        }
        
        int p = parent.front();
        parent.pop();
        
        // p has no children
        getTrees(parent, v, V, n);
        
        // p has children
        v[p] = Pair(p + 1 + parent.size(), p + 2 + parent.size());
        parent.push(v[p].first);
        parent.push(v[p].second);
        
        getTrees(parent, v, V, n-2);
    }
};
