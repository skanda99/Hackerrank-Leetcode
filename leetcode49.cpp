
// problem: "https://leetcode.com/problems/group-anagrams/"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sortedStringMap;
        prepareSortedStringMap(strs, sortedStringMap);
        return getGroupedAnagrams(sortedStringMap);
    }
    
private:
    void prepareSortedStringMap(vector<string> &strs, unordered_map<string, vector<string>> &sortedStringMap) {
        
        for (string &str: strs) {
            string strCopy = str;
            sort(strCopy.begin(), strCopy.end());
            if (sortedStringMap.find(strCopy) == sortedStringMap.end()) {
                sortedStringMap[strCopy] = vector<string> {str};
            } else {
                sortedStringMap[strCopy].push_back(str);
            }
        }
    }
    
    vector<vector<string>> getGroupedAnagrams(unordered_map<string, vector<string>> &sortedStringMap) {
        vector<vector<string>> strs;
        
        for (auto it=sortedStringMap.begin(); it != sortedStringMap.end(); it ++) {
            strs.push_back(it -> second);
        }
        
        return strs;
    }
};
