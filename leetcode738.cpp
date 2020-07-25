
// problem: "https://leetcode.com/problems/monotone-increasing-digits/"

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        deque<char>Q;
        
        int i,n;
        n = s.size();
        for(i=0;i!=n;i++) {
            if(Q.empty()) {
                Q.push_back(s[i]);
            }
            else {
                char c = s[i];
                bool pop = false;
                while(!Q.empty() && c < Q.back()) {
                    c = Q.back()-1;
                    Q.pop_back();
                    pop = true;
                }
                
                if(pop) {
                    Q.push_back(c);
                    
                    s = "";
                    while(!Q.empty()) {
                        s += string(1,Q.front());
                        Q.pop_front();
                    }
                    
                    int d = n-s.size();
                    while(d--) {
                        s += "9";
                    }
                    
                    break;
                }
                else {
                    Q.push_back(s[i]);
                }
            }
        }
        
        return stoi(s);
    }
};
