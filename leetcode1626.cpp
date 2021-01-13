
// problem: "https://leetcode.com/problems/best-team-with-no-conflicts/"

#define Pair pair<int, int>

bool func(Pair &p1, Pair &p2) {
    if(p1.first == p2.first) {
        return p1.second <= p2.second;
    }
    
    return p1.first < p2.first;
}

class Solution {
public:
    
    int maxScore(int i, int minAge, vector<Pair>&V, vector<vector<int>>&dp) {
        if(i < 0) {
            return 0;
        }
        
        if(dp[i][minAge] == -1) {
            int temp = 0;
            if(V[i].second <= minAge) {
                temp = maxScore(i-1, V[i].second, V, dp) + V[i].first;
            }
            
            dp[i][minAge] = max(temp, maxScore(i-1, minAge, V, dp));
        }
        
        return dp[i][minAge];
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<Pair>V;
        int i, n;
        
        n = scores.size();
        for(i=0;i!=n;i++) {
            V.push_back(Pair(scores[i], ages[i]));
        }
        
        sort(V.begin(), V.end(), func);
    
        // test
//         for(i=0;i!=n;i++) {
//             cout<<V[i].first<<' '<<V[i].second<<'\n';
//         }
        
//         return -1;
        
        vector<vector<int>>dp(n, vector<int>(1001, -1));
        
        return maxScore(n-1, 1000, V, dp);
    }
};
