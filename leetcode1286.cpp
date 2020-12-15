
// problem: "https://leetcode.com/problems/iterator-for-combination/"

class CombinationIterator {
public:
    int combLen, numChar;
    string charSet;
    vector<int>itrPos;
    bool nextPossible;
    
    CombinationIterator(string characters, int combinationLength) {
        combLen = combinationLength;
        numChar = characters.size();
        charSet = characters;
        itrPos = vector<int>(combLen);
        nextPossible = true;
        
        int i;
        for(i=0;i!=combLen;i++) {
            itrPos[i] = i;
        }
    }
    
    string buildString() {
        int i;
        string s = "";
        for(i=0;i!=combLen;i++) {
            s += charSet[itrPos[i]];
        }
        
        return s;
    }
    
    void nextItrPos() {
        int i,j;
        for(i=combLen-1;i!=-1;i--) {
            if(i == combLen-1) {
                if(itrPos[i]+1 <= numChar-1) {
                    itrPos[i]++;
                    break;
                }
            }
            else {
                if(itrPos[i]+1 != itrPos[i+1]) {
                    itrPos[i]++;
                    
                    for(j=i+1;j!=combLen;j++) {
                        itrPos[j] = itrPos[j-1]+1;
                    }
                    
                    break;
                }
            }
        }
        
        if(i == -1) {
            nextPossible = false;
        }
        else {
            nextPossible = true;
        }
    }
    
    string next() {
        string s = buildString();
        nextItrPos();
        return s;
    }
    
    bool hasNext() {
        return nextPossible;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
