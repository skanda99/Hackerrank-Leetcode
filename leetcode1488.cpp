
// problem: "https://leetcode.com/problems/avoid-flood-in-the-city/"

#define INF (int)(1e9)

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        int n, i;
        set<int>zero;
        n = rains.size();
        vector<int>ans(n, -1);
        unordered_map<int, int>M;
        
        for(i=0;i!=n;i++) {
            if(rains[i] == 0) {
                ans[i] = INF;
                zero.insert(i);
            }
            else {
                if(M.count(rains[i])) {
                    ans[i] = -1;
                    int l, r, z;
                    l = M[rains[i]]+1;
                    r = i-1;
                    auto it = zero.lower_bound(l);
                    
                    if(it == zero.end()) {
                        z = INF;
                    }
                    else {
                        z = *it;
                    }
                    
                    if(z <= r) {
                        ans[z] = rains[i];
                        zero.erase(z);
                    }
                    else {
                        return vector<int>();
                    }
                    
                    M[rains[i]] = i;
                }
                else {
                    M[rains[i]] = i;
                    ans[i] = -1;
                }
            }
        }
        
        return ans;
    }
};
