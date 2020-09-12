
// problem: "https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/"

#define Pair1 pair<vector<vector<bool>>,int>
#define Pair2 pair<int,int>

class Solution {
public:
    
    Pair2 findNotFilled(vector<vector<bool>>&v, int n, int m) {
        int i,j;
        for(i=0;i!=n;i++) {
            for(j=0;j!=m;j++) {
                if(!v[i][j]) {
                    return Pair2(i, j);
                }
            }
        }
        
        return Pair2(-1, -1);
    }
    
    int findMaxSquare(vector<vector<bool>>&v, int n, int m, int I, int J) {
        int i,j;
        for(i=I,j=J;i<n && j<m && !v[i][J] && !v[I][j];i++,j++) {}
        
        return i-I;
    }
    
    vector<vector<bool>> getFilled(int I, int J, int s, vector<vector<bool>>v) {
        int i,j;
        for(i=I;i<I+s;i++) {
            for(j=J;j<J+s;j++) {
                v[i][j] = true;
            }
        }
        
        return v;
    }
    
    int tilingRectangle(int n, int m) {
        
        int i;
        
        queue<Pair1>Q;
        Q.push(Pair1(vector<vector<bool>>(n, vector<bool>(m, false)), 0));
        
        while(!Q.empty()) {
            vector<vector<bool>>v(Q.front().first);
            int t(Q.front().second);
            Q.pop();
            
                    
            Pair2 p = findNotFilled(v, n, m);        // index of first non-filled
            
            if(p.first == -1) {
                return t;
            }
            
            int Max = findMaxSquare(v, n, m, p.first, p.second);        // get max sized square that can be put at p
            
            for(i=1;i!=Max+1;i++) {
                Q.push(Pair1(getFilled(p.first, p.second, i, v), t+1));      // copy of original v with square of size i filled at p
            }
        }
        
        return -1;
    }
};
