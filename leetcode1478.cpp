
// problem: "https://leetcode.com/problems/allocate-mailboxes/"

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        
        sort(houses.begin(),houses.end());
        int i,j,n;
        n = houses.size();
        vector<vector<int>>dist(n,vector<int>(n));

        for(i=0;i!=n;i++)
            for(j=i;j!=n;j++)
            {
                dist[i][j] = getMinDist(i,j,houses);
               // cout<<i<<' '<<j<<' '<<dist[i][j]<<'\n';
            }
        
        vector<vector<vector<int>>>V(n,vector<vector<int>>(n,vector<int>(k,-1)));
        return totalMinDist(0,0,k-1,dist,V);
    }
    
    int totalMinDist(int i,int j,int k,vector<vector<int>>&dist,vector<vector<vector<int>>>&V)
    {
        if(i >= V.size())
            return (int)1e9;
        
        if(k <= 0)
            return dist[i][V.size()-1];
        
        if(V[i][j][k] == -1)
            V[i][j][k] = min(totalMinDist(i+1,j,k,dist,V), totalMinDist(i+1,i+1,k-1,dist,V)+dist[j][i]);
        
        return V[i][j][k];
    }
    
    int getMinDist(int i,int j,vector<int>&houses)
    {
        int m,k,c;
        m = (j+i)/2;
        c = 0;
        for(k=i;k!=j+1;k++)
            c += abs(houses[m]-houses[k]);

        return c; 
    }
};
