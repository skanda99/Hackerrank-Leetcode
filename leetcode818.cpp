
// problem: "https://leetcode.com/problems/race-car/"

#define Pair pair<int,int>

class Solution {
public:
    int racecar(int target) {
        
        queue<Pair>Q;
        Q.push(Pair(0,1));
        vector<unordered_map<int,int>>V(16384);
        V[0][1] = 0;
        
        while(!Q.empty())
        {
            Pair p = Q.front();
            Q.pop();
            
            
            if(p.first == target)
                return V[p.first][p.second];
            
            if(p.first+p.second >= 0 && p.first+p.second < 16384 && !V[p.first+p.second].count(2*p.second))
            {
                Q.push(Pair(p.first+p.second,2*p.second));
                V[p.first+p.second][2*p.second] = V[p.first][p.second]+1;
            }
            
            if(p.second > 0)
            {
                if(!V[p.first].count(-1))
                {
                    Q.push(Pair(p.first,-1));
                    V[p.first][-1] = V[p.first][p.second]+1;
                }
            }
            else
            {
                if(!V[p.first].count(1))
                {
                    Q.push(Pair(p.first,1));
                    V[p.first][1] = V[p.first][p.second]+1;
                }
            }
        }
        
        return -1;
    }
    
};
