
// problem: "https://leetcode.com/problems/find-k-pairs-with-smallest-sums/"

#define Pair pair<int,int>

struct node {
    int i,j,s;
    
    node(int i, int j, int s=-1) : i(i), j(j), s(s) { }
};

struct comp{
    bool operator()(node &p1, node &p2) {
        return p1.s > p2.s;
    }
};


class Solution {
    
    public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        if(nums1.empty() || nums2.empty())
            return vector<vector<int>>();
        
        priority_queue<node,vector<node>,comp>Q;
        Q.push(node(0,0,nums1[0]+nums2[0]));
        vector<vector<int>>V;
        int n1,n2;
        
        n1 = nums1.size();
        n2 = nums2.size();
        
        set<Pair>S;
        
        while(!Q.empty() && k--)
        {
            node p = Q.top();
            Q.pop();
            
            V.push_back({nums1[p.i], nums2[p.j]});
            
            if(p.i+1 < n1 && !S.count(Pair(p.i+1, p.j))) {
                Q.push(node(p.i+1, p.j, nums1[p.i+1]+nums2[p.j]));
                S.insert(Pair(p.i+1, p.j));
            }
            
            if(p.j+1 < n2 && !S.count(Pair(p.i, p.j+1))) {
                Q.push(node(p.i, p.j+1, nums1[p.i]+nums2[p.j+1]));
                S.insert(Pair(p.i, p.j+1));
            }
        }
        
        return V;
    }
};
