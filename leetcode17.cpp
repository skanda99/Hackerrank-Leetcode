
// problem: "https://leetcode.com/problems/letter-combinations-of-a-phone-number/"

class Solution {
public:

    void mapString(string &s,int i,string t,vector<string>&V)
    {
        if(i >= s.size())
        {
            V.push_back(t);
            return;
        }

        if(s[i] == '1' || s[i] == '0')
            return;

        if(s[i] == '2')
        {
            mapString(s,i+1,t+"a",V);
            mapString(s,i+1,t+"b",V);
            mapString(s,i+1,t+"c",V);
        }
        else if(s[i] == '3')
        {
            mapString(s,i+1,t+"d",V);
            mapString(s,i+1,t+"e",V);
            mapString(s,i+1,t+"f",V);
        }
        else if(s[i] == '4')
        {
            mapString(s,i+1,t+"g",V);
            mapString(s,i+1,t+"h",V);
            mapString(s,i+1,t+"i",V);
        }
        else if(s[i] == '5')
        {
            mapString(s,i+1,t+"j",V);
            mapString(s,i+1,t+"k",V);
            mapString(s,i+1,t+"l",V);
        }
        else if(s[i] == '6')
        {
            mapString(s,i+1,t+"m",V);
            mapString(s,i+1,t+"n",V);
            mapString(s,i+1,t+"o",V);
        }
        else if(s[i] == '7')
        {
            mapString(s,i+1,t+"p",V);
            mapString(s,i+1,t+"q",V);
            mapString(s,i+1,t+"r",V);
            mapString(s,i+1,t+"s",V);
        }
        else if(s[i] == '8')
        {
            mapString(s,i+1,t+"t",V);
            mapString(s,i+1,t+"u",V);
            mapString(s,i+1,t+"v",V);
        }
        else if(s[i] == '9')
        {
            mapString(s,i+1,t+"w",V);
            mapString(s,i+1,t+"x",V);
            mapString(s,i+1,t+"y",V);
            mapString(s,i+1,t+"z",V);
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string>V;

        if(digits.empty())
            return V;

        mapString(digits,0,"",V);

        return V;
    }
};
