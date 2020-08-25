
// problem: "https://leetcode.com/problems/advantage-shuffle/"

#define Pair pair<int,int>

bool func(Pair &p1, Pair &p2) {
    return p1.second < p2.second;
}

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<Pair>V;
        int i,n;
        n = A.size();
        for(i=0;i!=n;i++) {
            V.push_back(Pair(i,B[i]));
        }
        
        sort(V.begin(), V.end(), func);
        
        priority_queue<int, vector<int>, greater<int>>Q;
        for(int x: A) {
            Q.push(x);
        }
        
        stack<int>S;
        i = 0;
        while(!Q.empty()) {
            int p = Q.top();
            Q.pop();
            
            if(p > V[i].second) {
                A[V[i].first] = p;
                i++;
            }
            else {
                S.push(p);
            }
        }
        
        while(i<n) {
            A[V[i].first] = S.top();
            S.pop();
            i++;
        }
        
        return A;
    }
};
