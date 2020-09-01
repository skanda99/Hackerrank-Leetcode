
// problem: "https://leetcode.com/problems/boats-to-save-people/"

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int i,j,c,n;
        n = people.size();
        c = 0;
        i = 0;
        j = n-1;
        
        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                i++;
                j--;
            }
            else {
                j--;
            }
            
            c++;
        }
        
        return c;
    }
};
