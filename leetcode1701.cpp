
// problem: "https://leetcode.com/problems/average-waiting-time/"

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long int i, n, chefTime, totalWaitTime;
        n = customers.size();
        chefTime = totalWaitTime = 0;
        
        for(i=0;i!=n;i++) {
            if(chefTime <= customers[i][0]) {
                totalWaitTime += customers[i][1];
                chefTime = customers[i][0] + customers[i][1];
            }
            else {
                totalWaitTime += customers[i][1] + chefTime - customers[i][0];
                chefTime += customers[i][1];
            }
        }
        
        return (double)totalWaitTime / n;
    }
};
