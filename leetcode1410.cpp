
// problem: "https://leetcode.com/problems/html-entity-parser/"

class Solution {
public:
    string entityParser(string text) {
        map<string,string>M;
        M["&quot;"] = "\"";
        M["&apos;"] = "'";
        M["&amp;"] = "&";
        M["&gt;"] = ">";
        M["&lt;"] = "<";
        M["&frasl;"] = "/";
        
        string s = "";
        int n = text.size();
        int i,j;
        j = i = 0;
        while(i < n)
        {
            if(text[i] != '&')
            {
                s.append(string(1,text[i]));
                i++;
            }
            else
            {
                j = i+3;
                while(j < n && j-i+1 < 8)
                {
                    string t = text.substr(i,j-i+1);
                    if(M.count(t))
                    {
                        s.append(M[t]);
                        i = j+1;
                        break;
                    }
                    
                    j++;
                }
                
                if(j >= n || j-i+1 >= 8)
                {
                    s.append(string(1,text[i]));
                    i++;
                }
            }
        }
        
        return s;
    }
};
