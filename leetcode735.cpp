
// problem: "https://leetcode.com/problems/asteroid-collision/"

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>S;
        for(int i: asteroids) {
            if(S.empty()) {
                S.push(i);
            }
            else if(S.top() > 0 && i < 0) {
                while(!S.empty() && S.top() > 0 && S.top() < -i) {
                    S.pop();
                }
                
                if(S.empty() || S.top() < 0) {
                    S.push(i);
                }
                else if(S.top() == -i) {
                    S.pop();
                }
            }
            else {
                S.push(i);
            }
        }
        
        vector<int>ans;
        while(!S.empty()) {
            ans.push_back(S.top());
            S.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
