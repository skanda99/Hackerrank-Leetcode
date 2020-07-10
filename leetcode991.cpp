
// problem: "https://leetcode.com/problems/broken-calculator/"


class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X == Y)
            return 0;
        
        if(X > Y)
            return X-Y;
        
        if(Y%2)
            return brokenCalc(X,Y+1)+1;
        
        return brokenCalc(X,Y/2)+1;
    }
};
