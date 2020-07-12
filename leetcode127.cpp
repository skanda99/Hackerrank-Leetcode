
// problem: "https://leetcode.com/problems/word-ladder/"


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if(wordList.empty())
            return 0;
        
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
        
        if(m == -1)
            return 0;
        
        vector<int>H(n+1,-1);
        bfs(n,G,H,m);
        
        return H[m]+1;
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
    
    void bfs(int n,vector<int>G[],vector<int>&H,int &m)
    {
        queue<int>Q;
        Q.push(n);
        H[n] = 0;
        
        while(!Q.empty())
        {
            int p = Q.front();
            Q.pop();
            
            int i;
            for(i=0;i!=G[p].size();i++)
            {
                if(H[G[p][i]] == -1)
                {
                    H[G[p][i]] = H[p]+1;
                    Q.push(G[p][i]);
                }
            }
        }        
    }    
}; 
