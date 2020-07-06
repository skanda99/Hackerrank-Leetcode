
// problem: "https://leetcode.com/problems/regular-expression-matching/"

class Solution {
public:
    bool isMatch(string &s, string &p) {
        
        int n,m;
        m = s.size()+1;
        
        s = " "+s;
        p = " "+p;
        
        n = countNonStar(p);
        
        vector<vector<bool>>V(n,vector<bool>(m,false));
        
        int i,j,c,I;
        // i -> p
        // I -> V (row)
        
        V[0][0] = true;
        I = i = 1;
        n = p.size();
        
        while(i < n)
        {
            c = 0;
            for(j=0;j!=m;j++)
            {
                if(i+1 < n && p[i+1] == '*')
                {
                    if(p[i] == '.')
                    {
                        if(I-1 >= 0 && j-1 >= 0 && V[I-1][j-1])
                        {
                            V[I][j] = true;
                            c++;
                        }
                        else if(I-1 >= 0 && V[I-1][j])
                        {
                            V[I][j] = true;
                            c++;
                        }
                        else if(j-1 >= 0 && V[I][j-1])
                        {
                            V[I][j] = true;
                            c++;
                        }
                    }
                    else
                    {
                        if(I-1 >= 0 && V[I-1][j])
                        {
                            V[I][j] = true;
                            c++;
                        }
                        else if(I-1 >= 0 && j-1 >= 0 && p[i] == s[j] && (V[I-1][j-1] || V[I][j-1]))
                        {
                            V[I][j] = true;
                            c++;
                        }
                    }
                }
                else
                {
                    if(I-1 >= 0 && j-1 >= 0 && V[I-1][j-1] && (p[i] == s[j] || p[i] == '.'))
                    {
                        V[I][j] = true;
                        c++;
                    }
                }
            }
            
            if(i+1 < n && p[i+1] == '*')
                i += 2;
            else
                i++;
            
            I++;
        }
        
        // printV(V);
        
        return V[V.size()-1][m-1];
    }
    
    void printV(vector<vector<bool>>&V)
    {
        int i,j;
        for(i=0;i!=V.size();i++)
        {
            for(j=0;j!=V[i].size();j++)
                cout<<V[i][j]<<' ';
            
            cout<<'\n';
        }
    }
    
    int countNonStar(string &p)
    {
        int i,c;
        c = 0;
        for(i=0;i!=p.size();i++)
            if(p[i] == '*')
                c++;
        
        return p.size()-c;
    }
};
