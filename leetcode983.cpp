
// problem: "https://leetcode.com/problems/minimum-cost-for-tickets/"

class Solution {
public:
    
    int getDays(vector<int>&days, int i, int n) {
        int j;
        for(j=i;j>=0 && days[i]-days[j]<n;j--);
        
        return j;
    }
    
    int minCost(int i, vector<int>&costs, vector<int>&days, vector<int>&V) {
        if(i < 0) {
            return 0;
        }
        
        if(V[i] == -1) {
            
            int j1, j2, j3;
            j1 = getDays(days, i, 1);
            j2 = getDays(days, i, 7);
            j3 = getDays(days, i, 30);
            
            int c1, c2, c3;
            c1 = minCost(j1, costs, days, V) + costs[0];
            c2 = minCost(j2, costs, days, V) + costs[1];
            c3 = minCost(j3, costs, days, V) + costs[2];
            
            V[i] = min(c1, min(c2, c3));
        }
        
        return V[i];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int>V(days.size(), -1);
        return minCost(days.size()-1, costs, days, V);
    }
}; 
