
// problem: "https://leetcode.com/problems/longest-string-chain/"

class Solution {
public:
    int longestStrChain(vector<string>& wordList) {
        
        vector<string>words[17];
        
        for(string s: wordList)
            words[s.size()].push_back(s);
        
        vector<int>chainL[17];
        int i,m,M;
        m = INT_MAX;
        M = 1;
        for(i=1;i!=17;i++)
        {
            if(words[i].empty())
                continue;
            
            if(m == INT_MAX || m < i-1)
            {
                m = i;
                chainL[i] = vector<int>(words[i].size(),1);
                continue;
            }
            
            int j,k;
            chainL[i] = vector<int>(words[i].size(),1);
            m = i;
            
            for(k=0;k!=words[i].size();k++)
                for(j=0;j!=words[i-1].size();j++)
                    if(match(words[i][k], words[i-1][j]))
                    {
                        chainL[i][k] = chainL[i-1][j]+1;
                        M = max(M,chainL[i][k]);
                    }
        }
        
        return M;
    }
    
    bool match(string &s1, string &s2)
    {
        int i,c,j;
        c = 0;
        for(i=0,j=0;i!=s1.size() && j!=s2.size();i++,j++)
            if(s1[i] != s2[j])
            {
                c++;
                j--;
            }
        
        if(c > 1)
            return false;
        
        return true;
    }
};
