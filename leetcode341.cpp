
// problem: "https://leetcode.com/problems/flatten-nested-list-iterator/"

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    
    vector<int>V;
    int it, n;
    bool nextExist;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        addNums(nestedList);
        it = 0;
        n = V.size();
        if(n > 0) {
            nextExist = true;
        }
        else {
            nextExist = false;
        }
    }
    
    int next() {
        it++;
        if(it >= n) {
            nextExist = false;
        }
        return V[it-1];
    }
    
    bool hasNext() {
        return nextExist;
    }
    
    void addNums(vector<NestedInteger>&v) {
        int i;
        for(i=0;i!=v.size();i++) {
            if(v[i].isInteger()) {
                V.push_back(v[i].getInteger());
            }
            else {
                addNums(v[i].getList());
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
