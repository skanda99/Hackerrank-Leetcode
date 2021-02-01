
// problem: "https://leetcode.com/problems/ambiguous-coordinates/"

class Solution {
public:
    
    void getPossibleNumbers(string number, vector<string>&A) {
        
        // without decimal validity
        if((number.size() > 1 && number[0] != '0') || (number.size() == 1)) {
            A.push_back(number);
        }
        
        if(number.size() > 1 && number[number.size()-1] != '0') {
            if(number[0] == '0') {
                A.push_back("0." + number.substr(1));
            }
            else {
                int i;
                for(i=0;i!=number.size()-1;i++) {
                    A.push_back(number.substr(0, i+1) + "." + number.substr(i+1));
                }
            }
        }
    }
    
    void mergeNumbers(vector<string>&A, vector<string>&B, vector<string>&ans) {
        int i, j;
        for(i=0;i!=A.size();i++) {
            for(j=0;j!=B.size();j++) {
                ans.push_back("(" + A[i] + ", " + B[j] + ")");
            }
        }
    }
    
    vector<string> ambiguousCoordinates(string S) {
        string number = S.substr(1, S.size()-2);
        vector<string>ans;
        
        int i;
        for(i=0;i!=number.size()-1;i++) {
            string p1 = number.substr(0, i+1);
            string p2 = number.substr(i+1);
            
            vector<string>A, B;
            getPossibleNumbers(p1, A);
            getPossibleNumbers(p2, B);
            
            mergeNumbers(A, B, ans);
        }
        
        return ans;
    }
};
