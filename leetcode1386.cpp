
// problem: "https://leetcode.com/problems/cinema-seat-allocation/"

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int i,m;
        m = reservedSeats.size();
        unordered_map<int,vector<bool>>M;
        
        for(i=0;i!=m;i++) {
            if(M.count(reservedSeats[i][0])) {
                M[reservedSeats[i][0]][reservedSeats[i][1]] = false;
            }
            else {
                M[reservedSeats[i][0]] = vector<bool>(10, true);
                M[reservedSeats[i][0]][reservedSeats[i][1]] = false;
            }
        }
        
        int count = 0, temp,c;
        c = 0;
        for(auto it: M) {
            vector<bool>V = it.second;
            temp = 0;
            
            if(V[2] && V[3] && V[4] && V[5]) {
                temp++;
            }
            
            if(V[6] && V[7] && V[8] && V[9]) {
                temp++;
            }
            
            if(!temp && V[4] && V[5] && V[6] && V[7]) {
                temp++;
            }
            
            count += temp;
            c++;
        }
        
        count += 2 * (n-c);
        return count;
    }
};
