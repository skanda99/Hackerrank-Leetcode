
// problem: "https://leetcode.com/problems/longest-substring-without-repeating-characters/"

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.empty())
            return 0;

        vector<bool>V(128,0);
        int i,j,M;

        M = 1;
        j = 0;
        V[s[0]] = 1;
        for(i=1;i<s.size();i++)
        {
            if(V[s[i]] == 1)
            {
                M = max(M,i-j);

                while(s[j] != s[i])
                {
                    V[s[j]] = 0;
                    j++;
                }

                j++;
            }

            V[s[i]] = 1;
        }

        M = max(M,i-j);

        return M;
    }
};
