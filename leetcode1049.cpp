
// problem: "https://leetcode.com/problems/last-stone-weight-ii/"

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int n = stones.size();
        vector<vector<int>>V(n,vector<int>(6001,INT_MIN));
        
        return minWeight(n-1,0,stones,V);
    }
    
    int minWeight(int i,int w,vector<int>&stones,vector<vector<int>>&V) {
        if(i < 0) {
            if(w < 0)
                return INT_MAX;
            
            else
                return w;
        }
        
        if(V[i][w+3000] == INT_MIN) {
            V[i][w+3000] = min(minWeight(i-1,w+stones[i],stones,V), minWeight(i-1,w-stones[i],stones,V));
        }
        
        return V[i][w+3000];
    }
};
