
// problem: "https://leetcode.com/problems/validate-stack-sequences/"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        if(pushed.empty())
            return true;
        
        vector<bool>V(1000,false);
        
        int i,j,n;
        n = popped.size();
        stack<int>S;
        i = j = 0;
        while(j < n)
        {
            if(V[popped[j]] && S.top() != popped[j])
                return false;
            
            else if(S.empty() || S.top() != popped[j])
            {
                while(i < n && pushed[i] != popped[j])
                {
                    S.push(pushed[i]);
                    V[pushed[i]] = true;
                    i++;
                }
                
                if(i >= n)
                    return false;
                
                i++;
            }
            else if(V[popped[j]])
            {
                V[popped[j]] = false;
                S.pop();
            }
            
            j++;
        }
        
        return true;
    }
};
