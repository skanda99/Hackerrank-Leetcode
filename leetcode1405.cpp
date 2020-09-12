
// problem: "https://leetcode.com/problems/longest-happy-string/"

#define Pair pair<int,int>

struct comp {
    bool operator()(Pair &p1, Pair &p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<Pair,vector<Pair>,comp>Q;
        
        if(a != 0) {
            Q.push(Pair(0, a));
        }
        
        if(b != 0) {
            Q.push(Pair(1, b));    
        }
        
        if(c != 0) {
            Q.push(Pair(2, c));    
        }
        
        string s = "";
        while(!Q.empty()) {
            Pair p = Q.top();
            Q.pop();
            
            char c = p.first+'a';
            
            if(s.size() < 2) {
                s.append(string(1, c));
                p.second--;
                
                if(p.second > 0) {
                    Q.push(p);
                }
            }
            else {
                int n = s.size();
                
                if(s[n-1] == c && s[n-2] == c) {
                    if(!Q.empty()) {
                        Pair t = Q.top();
                        Q.pop();
                        
                        t.second--;
                        s.append(string(1, t.first+'a'));
                        
                        if(t.second > 0) {
                            Q.push(t);
                        }
                        
                        Q.push(p);
                    }
                    else {
                        break;
                    }
                }
                else {
                    s.append(string(1, c));
                    p.second--;
                    
                    if(p.second > 0) {
                        Q.push(p);
                    }
                }
            }
            
            //cout<<s<<'\n';
        }
        
        return s;
    }
};
