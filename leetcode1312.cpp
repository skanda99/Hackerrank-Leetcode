
// problem: "https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/"

class Solution {
public:
    int minInsertions(string s) {
        
        vector<vector<int>>V(s.size(),vector<int>(s.size(),-1));
        return newLen(0,s.size()-1,V,s) - s.size();
    }
    
    int newLen(int i,int j,vector<vector<int>>&V,string &s)
    {
        if(i == j)
            return 1;
        else if(i > j)
            return 0;
        
        if(V[i][j] == -1)
        {
            if(s[i] == s[j])
                V[i][j] = newLen(i+1,j-1,V,s)+2;
            
            else
                V[i][j] = 2+min(newLen(i+1,j,V,s), newLen(i,j-1,V,s));
        }
        
        return V[i][j];
    }
};
