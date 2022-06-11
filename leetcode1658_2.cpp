
// problem: "https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> sumNums = getSumNums(nums);
        int i, j, n, total, minNumOperations, sumIJ;
        n = nums.size();
        total = sumNums[n-1];
        minNumOperations = INT_MAX;
        x = total - x;
        
        if (x == 0) {
            return n;
        }
        
        i = j = 0;
        
        while (j < n) {
            
            if (i > 0) {
                sumIJ = sumNums[j] - sumNums[i-1];
            } else {
                sumIJ = sumNums[j];
            }
            
            if (sumIJ == x) {
                minNumOperations = min(n-1-j+i, minNumOperations);
                i++;
            } else if (sumIJ < x) {
                j++;
            } else {
                i++;
            }
            
            if (i > j) {
                j = i;
            }
        }
        
        return minNumOperations == INT_MAX ? -1 : minNumOperations;
    }
    
private:
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
