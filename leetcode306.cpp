
// problem: "https://leetcode.com/problems/additive-number/"

#define ll long long

class Solution {
public:
    bool isAdditiveNumber(string num) {
        
        int l1, l2, n;
        n = num.size();
        
        if(n <= 2) {
            return false;
        }
        
        for(l1=1;l1!=min(18, n);l1++) {
            for(l2=1;l2!=min(18, n);l2++) {
                if(n - l1 - l2 < max(l1, l2)) {
                    continue;
                }
                
                if(checkAdditive(l1, l2, num, n)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool checkAdditive(int la, int lb, string &num, int n) {
        
        if(la > 1 && num.substr(0, la)[0] == '0') {
            return false;
        }
        
        if(lb > 1 && num.substr(la, lb)[0] == '0') {
            return false;
        }
        
        ll a, b, s;
        s = 0;
        a = stoll(num.substr(s, la));
        b = stoll(num.substr(la, lb));
        
        while(n-la-lb-s >= max(la, lb)) {
            ll c1 = stoll(num.substr(s+la+lb, max(la, lb)));
            if(max(la, lb) > 1 && num.substr(s+la+lb, max(la, lb))[0] == '0') {
                return false;
            }
            
            ll c2 = -1;
            
            if(n-la-lb-s >= max(la, lb)+1) {
                
                if(num.substr(s+la+lb, max(la, lb)+1)[0] != '0') {
                    c2 = stoll(num.substr(s+la+lb, max(la, lb)+1));
                }
            }
            
            if(a+b == c1) {
                s = s+la;
                a = b;
                b = c1;
                int m = max(la, lb);
                la = lb;
                lb = m;
            }
            
            else if(n-la-lb-s >= max(la, lb)+1 && a+b == c2) {
                s = s+la;
                a = b;
                b = c2;
                int m = max(la, lb);
                la = lb;
                lb = m+1;
            }
            
            else {
                return false;
            }
        }
        
        if(n == la+lb+s) {
            return true;
        }
        
        return false;
    }
};
