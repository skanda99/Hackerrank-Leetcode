
// problem: "https://leetcode.com/problems/odd-even-jump/"

#define Pair pair<int,int>

bool ascend(Pair &p1, Pair &p2) {
    if(p1.first == p2.first)
        return p1.second < p2.second;
    
    return p1.first < p2.first;
}

bool descend(Pair &p1, Pair &p2) {
    if(p1.first == p2.first)
        return p1.second < p2.second;
    
    return p1.first > p2.first;
}

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        
        int n = A.size();
        vector<Pair>V;
        int i;
        for(i=0;i!=n;i++)
            V.push_back(Pair(A[i],i));
        
        vector<int>oddJumps(n,-1);
        sort(V.begin(),V.end(),ascend);
        
        getJumps(oddJumps,V);
        
        vector<int>evenJumps(n,-1);
        sort(V.begin(),V.end(),descend);
        
        getJumps(evenJumps,V);
        
        printJ(oddJumps);
        printJ(evenJumps);
        
        int c = 1;
        vector<vector<bool>>dp(n,vector<bool>(2,false));
        dp[n-1][0] = dp[n-1][1] = true;
        
        for(i=n-2;i>=0;i--)
        {
            if(oddJumps[i] != -1 && dp[oddJumps[i]][0])
                dp[i][1] = true;
                
            if(evenJumps[i] != -1 && dp[evenJumps[i]][1])
                dp[i][0] = true;
            
            if(dp[i][1])
                c++;
        }
        
        return c;
    }
    
    void printJ(vector<int>&v)
    {
        for(int i: v)
            cout<<i<<' ';
        
        cout<<'\n';
    }
    
    void getJumps(vector<int>&jumps,vector<Pair>&V)
    {
        stack<int>Q;
        int i,n;
        n = V.size();
        for(i=0;i!=n;i++)
        {
            if(Q.empty() || Q.top() > V[i].second)
                Q.push(V[i].second);
            
            else
            {
                while(!Q.empty() && Q.top() < V[i].second)
                {
                    jumps[Q.top()] = V[i].second;
                    Q.pop();
                }
                
                Q.push(V[i].second);
            }
        }
    }
};
