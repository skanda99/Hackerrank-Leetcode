
// problem: "https://leetcode.com/problems/simplify-path/"

class Solution {
public:
    string simplifyPath(string path) {
        
        deque<char>Q;
        Q.push_back('/');
        int i=0;
        while(i < path.size())
        {
            if(path[i] == '/' && Q.back() != '/')
            {
                Q.push_back('/');
                i++;
            }
            else if(path[i] == '.' && Q.back() == '/' && i+1 < path.size() && path[i+1] == '.' && (i+2 < path.size() && 
                                                                path[i+2] == '/' || i+2 == path.size()))
            {
                Q.pop_back();

                if(Q.empty())
                    Q.push_front('/');

                while(!Q.empty() && Q.back() != '/')
                    Q.pop_back();
                
                i += 2;
            }
            else if(path[i] == '.' && Q.back() == '/' && (i+1 < path.size() && path[i+1] == '/' || i+1 == path.size()))
            {
                i++;
            }
            else if(path[i] != '/')
            {
                Q.push_back(path[i]);
                i++;
            }
            else
                i++;
        }
        
        string s = "";
        while(!Q.empty())
        {
            s += string(1,Q.front());
            Q.pop_front();
        }
        
        if(s[s.size()-1] == '/' && s.size() != 1)
            s = s.erase(s.size()-1,1);
        
        return s;
    }
};
