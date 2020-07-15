
// problem: "https://leetcode.com/problems/find-k-closest-elements/"

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int c, int x) {
        
        int n = arr.size();
        int i,j,k;
        
        k = findX(0,n-1,x,arr);
        vector<int>v;
        
        if(k == -1)
        {
            for(i=0;i!=c;i++)
                v.push_back(arr[i]);
            
            return v;
        }
        
        deque<int>Q;
        i = k;
        j = k+1;
        k = 0;
        
        while(i >= 0 && j < n && k  < c)
        {
            if(x-arr[i] <= arr[j]-x)
            {
                Q.push_front(arr[i]);
                k++;
                i--;
            }
            else
            {
                Q.push_back(arr[j]);
                k++;
                j++;
            }
        }
        
        while(i >= 0 && k < c)
        {
            Q.push_front(arr[i]);
            i--;
            k++;
        }
        
        while(j < n && k < c)
        {
            Q.push_back(arr[j]);
            j++;
            k++;
        }
        
        while(!Q.empty())
        {
            v.push_back(Q.front());
            Q.pop_front();
        }
        
        return v;
    }
    
    int findX(int i,int j,int n,vector<int>&V)
    {
        if(i > j)
            return j;
        
        int m = (i+j)/2;
        
        if(V[m] == n)
            return m;
        
        else if(V[m] < n)
            return findX(m+1,j,n,V);
        
        return findX(i,m-1,n,V);
    }
};
