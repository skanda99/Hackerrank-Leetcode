
// problem: "https://leetcode.com/problems/insert-interval/"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        if(intervals.empty() || newInterval[1] < intervals[0][0])
        {
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        
        if(newInterval.empty())
            return intervals;
        
        int i;
        vector<vector<int>>V;
        
        for(i=0;i!=intervals.size();i++)
        {
            if(intervals[i][1] < newInterval[0])
                V.push_back(intervals[i]);
            else 
                break;
        }
        
        if(i == intervals.size())
        {
            V.push_back(newInterval);
            return V;
        }
        
        if(newInterval[1] < intervals[i][0])
        {
            V.push_back(newInterval);
            V.push_back(intervals[i]);
        }
        else
            V.push_back({min(intervals[i][0],newInterval[0]),max(intervals[i][1],newInterval[1])});
        
        int j = V.size()-1;
        for(i++;i!=intervals.size();i++)
        {
            if(V[j][1] >= intervals[i][0])
            {
                V[j][0] = min(V[j][0],intervals[i][0]);
                V[j][1] = max(V[j][1],intervals[i][1]);
            }
            else
            {
                V.push_back(intervals[i]);
                j++;
            }
        }
        
        return V;
    }
};
