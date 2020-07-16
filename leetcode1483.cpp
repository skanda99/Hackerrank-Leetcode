
// problem: "https://leetcode.com/problems/kth-ancestor-of-a-tree-node/"

#define Pair pair<int,int>

class TreeAncestor {
public:
    vector<int>G[50000];
    vector<Pair>Child;
    vector<bool>Leaf;
    
    TreeAncestor(int n, vector<int>& parent) {
        
        int i;
        
        Child = vector<Pair>(n,Pair(-2,-2));
        Leaf = vector<bool>(n,true);
        
        for(int i: parent)
            if(i != -1)
                Leaf[i] = false;
        
        for(i=0;i!=n;i++)
            if(Leaf[i])
                generateLeafAncestors(i,parent);
        
    }
    
    void generateLeafAncestors(int i,vector<int>&parent)
    {
        int p = i;
        while(parent[p] != -1)
        {
            G[i].push_back(parent[p]);
            
            if(Child[parent[p]].first == -2)
                Child[parent[p]] = Pair(i,G[i].size());
            
            p = parent[p];
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        if(!Leaf[node])
        {
            int p = Child[node].first;
            int m = Child[node].second;
            
            if( G[p].size() >= m+k)
                return G[p][m+k-1];
            
            return -1;
        }
        
        if(G[node].size() >= k)
            return G[node][k-1];
    
        return -1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
