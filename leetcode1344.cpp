
// problem: "https://leetcode.com/problems/angle-between-hands-of-a-clock/"

class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double angle_hour = (hour%12)*30 + minutes/2.0;
        double angle_minutes = 6 * minutes;
        
        double angle = abs(angle_hour-angle_minutes);
        
        return min(angle,360-angle);
    }
};
