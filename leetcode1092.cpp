
// problem: "https://leetcode.com/problems/shortest-common-supersequence/"

#define Pair pair<int,int>

class Solution {
public:
    
    map<Pair,Pair>links;
    
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n1,n2;
        n1 = str1.size();
        n2 = str2.size();
        
        vector<vector<int>>V(n1,vector<int>(n2,-1));
        
        cout<<getMinSuper(0,0,str1,str2,n1,n2,V);
        
        int i,j;
        Pair p(0,0);
        
        string s = "";
        
        while(links.count(p)) {
            
            Pair t = links[p];
            
            if(t.first != p.first) {
                s += str1[p.first];
            }
            else {
                s += str2[p.second];
            }
            
            p = t;
        }
        
        i = p.first;
        j = p.second;
        
        while(i < n1) {
            s += str1[i];
            i++;
        }
        
        while(j < n2) {
            s += str2[j];
            j++;
        }
        
        return s;
    }
    
    int getMinSuper(int i,int j,string &s1,string &s2,int &n1,int &n2,vector<vector<int>>&V) {
        
        if(i >= n1) {
            return n2-j;
        }
        
        if(j >= n2) {
            return n1-i;
        }
        
        if(V[i][j] == -1) {
            
            if(s1[i] == s2[j]) {
                links[Pair(i,j)] = Pair(i+1,j+1);
                V[i][j] = getMinSuper(i+1,j+1,s1,s2,n1,n2,V)+1;
            }
            else {
                int m1,m2;
                
                m1 = getMinSuper(i+1,j,s1,s2,n1,n2,V);
                m2 = getMinSuper(i,j+1,s1,s2,n1,n2,V);
                
                if(m1 < m2) {
                    links[Pair(i,j)] = Pair(i+1,j);
                    V[i][j] = m1+1;
                }
                else {
                    links[Pair(i,j)] = Pair(i,j+1);
                    V[i][j] = m2+1;
                }
            }
        }
        
        return V[i][j];
    }
};
