
// problem: "https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> sumNums = getSumNums(nums);
        int i, j, numOperations, n;
        numOperations = INT_MAX;
        n = sumNums.size();
        
        for (i = 0; i != sumNums.size(); i++) {
            j = getIndexOfXMinusSumI(i+1, n-1, sumNums, x-sumNums[i]);
            
            if (j > i) {
                numOperations = min(i+1+n-j, numOperations);
            }
        }
        
        for (i = 0; i != sumNums.size(); i++) {
            if (sumNums[i] == x) {
                numOperations = min(i+1, numOperations);
            }
            
            if (i > 0 && sumNums[n-1] - sumNums[i-1] == x) {
                numOperations = min(n-i, numOperations);
            }
        }
        
        return numOperations == INT_MAX ? -1 : numOperations;
    }
    
private:
    int getIndexOfXMinusSumI(int start, int end, vector<int> &sumNums, int numToFind) {
        int middle;
        
        while (start <= end) {
            middle = (start+end) / 2;
            
            if (sumNums[sumNums.size()-1] - sumNums[middle-1] == numToFind) {
                return middle;
            } else if (sumNums[sumNums.size()-1] - sumNums[middle-1] < numToFind) {
                end = middle-1;
            } else {
                start = middle + 1;
            }
        }
        
        return -1;
    }
    
    vector<int> getSumNums(vector<int> &nums) {
        vector<int> sumNums;
        int sum = 0;
        
        for (int num: nums) {
            sum += num;
            sumNums.push_back(sum);
        }
        
        return sumNums;
    }
};
