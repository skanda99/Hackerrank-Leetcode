
// problem: "https://leetcode.com/problems/candy/"

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        if(n <= 1) {
            return n;
        }
        
        int i;
        queue<int>Q;
        vector<int>V(n,-1);
        for(i=0;i!=n;i++) {
            if(i-1 >= 0 && i+1 < n) {
                if(ratings[i-1] >= ratings[i] && ratings[i] <= ratings[i+1]) {
                    Q.push(i);
                    V[i] = 1;
                }
            }
            
            else if(i-1 >= 0) {
                if(ratings[i] <= ratings[i-1]) {
                    Q.push(i);
                    V[i] = 1;
                }
            }
            
            else {
                if(ratings[i] <= ratings[i+1]) {
                    Q.push(i);
                    V[i] = 1;
                }
            }
        }
        
        while(!Q.empty()) {
            i = Q.front();
            Q.pop();
            
            // check left
            if(i-1 >= 0 && V[i-1] == -1) {
                if(i-2 >= 0 && ratings[i-2] >= ratings[i-1] && ratings[i-1] > ratings[i]) {
                    V[i-1] = V[i]+1;
                    Q.push(i-1);
                }
                else if(i-2 < 0 && ratings[i-1] > ratings[i]) {
                    V[i-1] = V[i]+1;
                }
            }
            
            // check right
            if(i+1 < n && V[i+1] == -1) {
                if(i+2 < n && ratings[i] < ratings[i+1] && ratings[i+1] <= ratings[i+2]) {
                    V[i+1] = V[i]+1;
                    Q.push(i+1);
                }
                else if(i+2 >= n && ratings[i+1] > ratings[i]) {
                    V[i+1] = V[i]+1;
                }
            }
        }
        
        for(i=0;i!=n;i++) {
            if(V[i] == -1) {
                
                if(ratings[i] == ratings[i-1]) {
                    V[i] = V[i+1]+1;
                }
                else if(ratings[i] == ratings[i+1]) {
                    V[i] = V[i-1]+1;
                }
                else {
                    V[i] = max(V[i-1], V[i+1]) + 1;
                }
                
            }
        }
        
        int c = 0;
        for(i=0;i!=n;i++) {
            c += V[i];
        }
        
        return c;
    }
};
