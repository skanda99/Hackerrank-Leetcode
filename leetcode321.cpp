
// problem: "https://leetcode.com/problems/create-maximum-number/"

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        
        // test
        // string s1 = "990";
        // string s2 = "98350";
        // cout<<merge(s1,s2);
        
        // return vector<int>();
        
        int n1,n2;
        n1 = nums1.size();
        n2 = nums2.size();
        
        vector<string>V1(n1+1,"");
        buildV(V1,nums1,n1);

        vector<string>V2(n2+1,"");
        buildV(V2,nums2,n2);
        
        int i;
        string s = "";
        for(i=0;i!=k+1;i++) {
            if(i <= n1 && k-i <= n2) {
                
                //cout<<i<<' '<<V1[i][0]<<' '<<V2[k-i][0]<<'\n';
                string t = merge(V1[i], V2[k-i]);
                //cout<<t<<'\n';
                if(aGreaterb(t,s)) {
                    s = t;
                }
            }
        }
        
        vector<int>ans;
        for(char c: s) {
            ans.push_back(c-'0');
        }
        
        return ans;
    }
    
    string merge(string &s1, string &s2) {
        int i,j,k,n1,n2;
        n1 = s1.size();
        n2 = s2.size();
        
        string s = "";
        i = j = k = 0;
        while(k < n1+n2) {
            if(takeI(s1,i,n1,s2,j,n2)) {
                s += string(1,s1[i]);
                i++;
                k++;
            }
            else {
                s += string(1,s2[j]);
                j++;
                k++;
            }
        }
        
        return s;
    }
    
    bool takeI(string &s1,int i,int &n1,string &s2,int j,int &n2) {
        
        while(i < n1 && j < n2) {
            if(s1[i] != s2[j]) {
                return s1[i] > s2[j];
            }
            
            i++;
            j++;
        }
        
        if(i < n1) {
            return true;
        }
        
        return false;
    }
    
    void buildV(vector<string>&V, vector<int>&A,int &n) {
        int l,i,j;
        string s = "";
        for(int i: A) {
            s += string(1,i+'0');
        }
        
        V[n] = s;
        l = n-1;
        while(l>0) {
            for(i=0;i!=s.size()-1;i++) {
                if(s[i] < s[i+1]) {
                    break;
                }
            }
            
            V[l] = s.substr(0,i) + s.substr(i+1);
            s = V[l];
            l--;
        }
    }
    
    bool aGreaterb(string &s1, string &s2) {
        int n1,n2;
        n1 = s1.size();
        n2 = s2.size();
        
        if(n1 != n2) {
            return n1>n2;
        }
        
        int i;
        for(i=0;i!=n1;i++) {
            if(s1[i] != s2[i]) {
                return s1[i] > s2[i];
            }
        }
        
        return false;
    }
    
};
