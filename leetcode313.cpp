
// problem: "https://leetcode.com/problems/super-ugly-number/"

#define ll long long

struct comp {
    bool operator()(int &p1, int &p2) {
        return p1 > p2;
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int i = 0;
        priority_queue<int,vector<int>,comp>Q;
        Q.push(1);
        unordered_set<int>S;
        S.insert(1);
        
        while(i < n)
        {
            i++;
            if(i == n)
                return Q.top();
            
            int m = Q.top();
            Q.pop();
            
            for(int j: primes)
            {
                if((ll)m*j < INT_MAX && !S.count(m*j) && )
                {
                    Q.push(m*j);
                    S.insert(m*j);
                }
            }
        }
        
        return 0;
    }
};
