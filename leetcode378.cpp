
// problem: "https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/"

struct node {
    int i, j, v;
    
    node(int i, int j, int v) : i(i), j(j), v(v) { }
};

struct comp {
    bool operator()(node &p1, node &p2) {
        return p1.v > p2.v;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        priority_queue<node,vector<node>,comp>Q;
        Q.push(node(0,0,matrix[0][0]));
        
        vector<vector<bool>>V(n,vector<bool>(n,false));
        V[0][0] = true;
        
        node ans(-1,-1,-1);
        
        while(!Q.empty() && k--) {
            node p = Q.top();
            Q.pop();
            
            ans = p;
            
            if(p.i+1 < n && !V[p.i+1][p.j]) {
                V[p.i+1][p.j] = true;
                Q.push(node(p.i+1,p.j,matrix[p.i+1][p.j]));
            }
            
            if(p.j+1 < n && !V[p.i][p.j+1]) {
                V[p.i][p.j+1] = true;
                Q.push(node(p.i,p.j+1,matrix[p.i][p.j+1]));
            }
        }
        
        return matrix[ans.i][ans.j];
    }   
};
