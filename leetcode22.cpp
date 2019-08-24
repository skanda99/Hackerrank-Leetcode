
// problem: "https://leetcode.com/problems/generate-parentheses/"

class Solution {
public:
    void genP(int n,int i,int j,string s,vector<string>&V)
    {
        if(i == n && j == n)
        {
            V.push_back(s);
            return;
        }

        if(i == n)
        {
            s.append(")");
            genP(n,i,j+1,s,V);
            return;
        }

        if(i == j)
        {
            s.append("(");
            genP(n,i+1,j,s,V);
            return;
        }

        genP(n,i+1,j,s+"(",V);
        genP(n,i,j+1,s+")",V);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string>V;
        string s;
        genP(n,0,0,s,V);

        return V;
    }
};
