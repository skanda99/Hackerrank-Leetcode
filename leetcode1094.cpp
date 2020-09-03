
// problem: "https://leetcode.com/problems/car-pooling/"

bool func1 (vector<int>&p1, vector<int>&p2) {
    return p1[1] < p2[1];
}

bool func2 (vector<int>&p1, vector<int>&p2) {
    return p1[2] < p2[2];
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        if(trips.empty()) {
            return true;
        }
        
        vector<vector<int>>trips_c(trips);
        
        sort(trips.begin(), trips.end(), func1);
        sort(trips_c.begin(), trips_c.end(), func2);
        
        int i,j,n;
        i = j = 0;
        n = trips.size();
        
        while(i < n) {it
            if(trips_c[j][2] <= trips[i][1]) {
                capacity += trips_c[j][0];
                j++;
            }
            else {
                capacity -= trips[i][0];
                i++;
            }
            
            if(capacity < 0) {
                return false;
            }
        }
        
        return true;
    }
};
