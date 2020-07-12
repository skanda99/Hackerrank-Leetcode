
// problem: "https://leetcode.com/problems/word-ladder-ii/"

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        vector<vector<string>>V;
        if(wordList.empty())
            return V;
        
        int n = wordList.size();
        vector<int>G[n+1];
        int i,j,m;
        m = -1;
        for(i=0;i!=n-1;i++)
        {
            for(j=i+1;j!=n;j++)
            {
                if(ifBridge(wordList[i],wordList[j]))
                {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        
        for(i=0;i!=n;i++)
        {
            if(endWord == wordList[i])
                m = i;
            
            if(ifBridge(beginWord,wordList[i]))
                G[n].push_back(i);
        }
        
        // printGraph(G,n);
        
        if(m == -1)
            return V;
        
        wordList.push_back(beginWord);
        vector<vector<int>>V_i;
        vector<int>H(n+1,-1);
        bfs(n,vector<int>(),G,V_i,H,m);
        
        // printH(H,n);
        
        for(i=0;i!=V_i.size();i++)
        {
            V.push_back(vector<string>(V_i[i].size(),""));
            for(j=0;j!=V_i[i].size();j++)
                // V[i].push_back(wordList[V_i[i][j]]);
                V[i][j] = wordList[V_i[i][j]];
        }
        
        return V;
    }
    
    void printH(vector<int>&H,int n)
    {
        int i;
        for(i=0;i!=n+1;i++)
            cout<<i<<' '<<H[i]<<'\n';
    }
    
    void printGraph(vector<int>G[],int n)
    {
        int i,j;
        for(i=0;i!=n+1;i++)
        {
            cout<<i<<"--->\n";
            
            for(j=0;j!=G[i].size();j++)
                cout<<G[i][j]<<' ';
            
            cout<<'\n';
        }
    }
    
    bool ifBridge(string &s1, string &s2)
    {
        int i,c,n;
        n = s1.size();
        c = 0;
        for(i=0;i!=n;i++)
            if(s1[i] != s2[i])
                c++;
        
        if(c > 1)
            return false;
        
        return true;
    }
    
    void bfs(int n,vector<int>v,vector<int>G[],vector<vector<int>>&V_i,vector<int>&H,int &m)
    {
        queue<vector<int>>Q;
        v.push_back(n);
        Q.push(v);
        H[n] = 0;
            
        while(!Q.empty())
        {
            vector<int>p = Q.front();
            int l = p[p.size()-1];
            Q.pop();
            
            if(l == m)
                V_i.push_back(p);
            
            
            int i;
            for(i=0;i!=G[l].size();i++)
            {
                vector<int>p_copy(p);
                if(H[G[l][i]] == -1)
                {
                    H[G[l][i]] = H[l]+1;
                    p_copy.push_back(G[l][i]);
                    Q.push(p_copy);
                }
                else if(H[G[l][i]] == H[l]+1)
                {
                    p_copy.push_back(G[l][i]);
                    Q.push(p_copy);
                }
            }
        }
    }
};
