
// problem: "https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/"

class Solution {
public:
    vector<int> numOfBurgers(int T, int C) {
        vector<int>V;
        
        if((T-2*C)%2 == 0 && T >= 2*C && (4*C-T)%2 == 0 && 4*C >= T) {
            V = {(T-2*C)/2, (4*C-T)/2};
        }
        
        return V;
    }
};
