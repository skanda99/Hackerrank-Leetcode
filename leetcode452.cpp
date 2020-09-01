
// problem: "https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/"

bool func (vector<int>&p1, vector<int>&p2) {
    if(p1[1] == p2[1]) {
        return p1[0] < p2[0];    
    }
    
    return p1[1] < p2[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(points.empty()) {
            return 0;
        }
        
        sort(points.begin(), points.end(), func);
        
        int i,n,m;
        n = points.size();
        m = 0;
        long l = 1e12;
        for(i=n-1;i>=0;i--) {
            
            cout<<points[i][0]<<' '<<points[i][1]<<'\n';
            
            if(points[i][1] < l) {
                m++;
                l = points[i][0];
            }
            else {
                l = max(l, (long)points[i][0]);
            }
        }
        
        return m;
    }
};
