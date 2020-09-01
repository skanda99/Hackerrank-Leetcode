
// problem: "https://leetcode.com/problems/non-overlapping-intervals/"

bool func (vector<int>&p1, vector<int>&p2) {
    return p1[1] < p2[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.empty()) {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), func);
        
        int s,l,i,n;
        n = intervals.size();
        l = 1e9;
        s = 0;
        
        for(i=n-1;i>=0;i--) {
            if(intervals[i][1] <= l) {
                s++;
                l = intervals[i][0];
            }
            else {
                l = max(intervals[i][0], l);
            }
        }
        
        return n-s;
    }
};
