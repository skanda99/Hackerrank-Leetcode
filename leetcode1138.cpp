

// problem: "https://leetcode.com/problems/alphabet-board-path/"

class Solution {
public:
    string alphabetBoardPath(string target) {
        
        int i, x, y;
        x = y = 0;
        
        string path = "";
        
        for(i=0;i!=target.size();i++) {
            int d, u, r, l;
            d = getDown(target[i], x, y);
            u = getUp(target[i], x, y);
            r = getRight(target[i], x, y);
            l = getLeft(target[i], x, y);
            
            y += d + u;
            x += l + r;
            
            setPath(path, d, u, l, r);
        }
        
        return path;
    }
    
    void setPath(string &path, int d, int u, int l, int r) {
        d = abs(d);
        u = abs(u);
        l = abs(l);
        r = abs(r);
        
        
        while(u--) {
            path += "U";
        }
        
        while(r--) {
            path += "R";
        }
        
        while(l--) {
            path += "L";
        }
        
        while(d--) {
            path += "D";
        }
        
        path += "!";
    }
    
    int getDown(char c, int x, int y) {
        if((c-'a')/5 - y <= 0) {
            return 0;
        }
        
        return (c-'a')/5 - y;
    }
    
    int getUp(char c, int x, int y) {
        if((c-'a')/5 - y >= 0) {
            return 0;
        }
        
        return (c-'a')/5 - y;
    }
    
    int getRight(char c, int x, int y) {
        if((c-'a')%5 - x <= 0) {
            return 0;
        }
        
        return (c-'a')%5 - x;
    }
    
    int getLeft(char c, int x, int y) {
        if((c-'a')%5 - x >= 0) {
            return 0;
        }
        
        return (c-'a')%5 - x;
    }
};
