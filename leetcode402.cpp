
// problem: "https://leetcode.com/problems/remove-k-digits/"

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>Q;
        int i,n;
        n = num.size();
        for(i=0;i!=n;i++) {
            if(Q.empty()) {
                if(num[i] != '0') {
                   Q.push(num[i]);
                }
            }
            else {
                while(!Q.empty() && num[i] < Q.top() && k) {
                    Q.pop();
                    k--;
                }
                
                if(num[i] != '0') {
                    Q.push(num[i]);
                }
                else if(num[i] == '0' && !Q.empty()) {
                    Q.push(num[i]);
                }
            }
        }
        
        while(!Q.empty() && k--) {
            Q.pop();
        }
        
        string s = "";
        while(!Q.empty()) {
            s += Q.top();
            Q.pop();
        }
        
//         i = s.size()-1;
//         while(i >= 0 && s[i] == '0') {
//             i--;
//         }
        
//         s = s.substr(0,i+1);
        
        reverse(s.begin(),s.end());
        
        if(s.empty()) {
            s = "0";
        }
        
        return s;
    }
};
