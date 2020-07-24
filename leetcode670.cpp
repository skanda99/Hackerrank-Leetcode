
// problem: "https://leetcode.com/problems/maximum-swap/"

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int i;
        int n = s.size();
        
        vector<int>V(n,n-1);
        for(i=n-2;i>=0;i--) {
            if(s[i+1] > s[V[i+1]]) {
                V[i] = i+1;                
            }
            else {
                V[i] = V[i+1];
            }
        }
        
        for(i=0;i!=n-1;i++) {
            if(s[i] < s[V[i]]) {
                swap(s[i],s[V[i]]);
                break;
            }
        }
        
        return stoi(s);
    }
};
