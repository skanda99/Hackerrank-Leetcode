
// problem: "https://leetcode.com/problems/push-dominoes/"

class Solution {
public:
    string pushDominoes(string s) {
        stack<int>S;
        for(int i=0;i!=s.size();i++) {
            if(S.empty()) {
                if(s[i] == 'R') {
                    S.push(i);
                }
                else if(s[i] == '.') {
                    S.push(i);
                }
            }
            else {
                if(s[i] == 'L') {
                    int j;
                    while(!S.empty()) {
                        j = S.top();
                        
                        if(s[j] == 'R') {
                            j++;
                            int k = i-1;
                            
                            while(j <= k) {
                                if(j == k) {
                                    s[j] = '.';
                                }
                                else {
                                    s[j] = 'R';
                                }
                                
                                j++;
                                k--;
                            }
                        }
                        else {
                            s[j] = 'L';
                        }
                        
                        S.pop();
                    }
                }
                else if(s[i] == 'R') {
                    while(!S.empty()) {
                        int j = S.top();
                       
                        if(s[j] == 'R') {
                            while(j < i) {
                                s[j] = 'R';
                                j++;
                            }
                        }

                        S.pop();
                    }
                    
                    S.push(i);
                }
                else {
                    S.push(i);
                }
            }
        }
        
        while(!S.empty()) {
            int j = S.top();
            if(s[j] == 'R') {
                while(j < s.size()) {
                    s[j] = 'R';
                    j++;
                }
            }
            
            S.pop();
        }
        
        return s;
    }
};
