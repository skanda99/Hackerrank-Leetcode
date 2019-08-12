
// problem: "https://leetcode.com/problems/longest-palindromic-substring/"

class Solution {
public:

    string check(string &s,int j,int k)
    {
        while(s[j] == s[k])
        {
            j--;
            k++;

            if(j<0 || k>=s.size())
                break;
        }

        string p;
        p.assign(s.begin()+j+1,s.begin()+k);
        return p;
    }

    string longestPalindrome(string s)
    {
        if(s.size()<=1)
            return s;

        if(s.size()==2)
        {
            if(s[0]==s[1])
                return s;

            s.erase(s.begin()+1,s.end());
            return s;
        }

        int i,j,k;
        string p;
        p.assign(s.begin(),s.begin()+1);

        for(i=1;i<s.size()-1;i++)
        {
            if(s[i-1] == s[i+1])
            {
                string t = check(s,i-1,i+1);

                if(p.size() < t.size())
                    p = t;
            }

            if(s[i] == s[i+1])
            {
                string t = check(s,i,i+1);

                if(p.size() < t.size())
                    p = t;
            }

            if(s[i] == s[i-1])
            {
                string t = check(s,i-1,i);

                if(p.size() < t.size())
                    p = t;
            }
        }

        return p;
    }
};
