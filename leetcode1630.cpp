
// problem: "https://leetcode.com/problems/arithmetic-subarrays/"

#define Pair pair<int, int>

class Solution {
public:
    
    bool static func(Pair p1, Pair p2) {
        return p1.first > p2.first;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<Pair>V;
        int i;
        for(i=0;i!=nums.size();i++) {
            V.push_back(Pair(nums[i], i));
        }
        
        sort(V.begin(), V.end(), func);
        
        vector<bool>ans;
        for(i=0;i!=l.size();i++) {
            ans.push_back(checkArithmetic(V, l[i], r[i]));
        }
        
        return ans;
    }
    
    bool checkArithmetic(vector<Pair>&V, int l, int r) {
        int i, a, j, d;
         a = d = 1e6;
        for(i=0;i!=V.size();i++) {
            j = V[i].second;
            if(j >= l && j <= r) {
                if(a == 1000000) {
                    a = V[i].first;
                }
                else if(d == 1000000) {
                    d = V[i].first - a;
                    a = V[i].first;
                }
                else if(d != V[i].first-a) {
                    return false;
                }
                else {
                    a = V[i].first;
                }
            }
        }
        
        return true;
    }
};
