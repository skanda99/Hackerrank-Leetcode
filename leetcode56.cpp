// problem: "https://leetcode.com/problems/merge-intervals/"

bool isOrderCorrect(vector<int> I1, vector<int> I2) {
    return I1[0] < I2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), isOrderCorrect);
        return mergeSortedIntervals(intervals);
    }
    
private:
    
    vector<vector<int>> mergeSortedIntervals(vector<vector<int>> &intervals) {
        vector<vector<int>> mergedIntervals;
        
        for (vector<int> &interval: intervals) {
            if (mergedIntervals.empty() || mergedIntervals.back()[1] < interval[0]) {
                mergedIntervals.push_back(interval);
            } else {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[1]);
            }
        }
        
        return mergedIntervals;
    }
};
