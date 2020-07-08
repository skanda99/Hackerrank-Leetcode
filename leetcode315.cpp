
// problem: "https://leetcode.com/problems/count-of-smaller-numbers-after-self/"

#define Pair pair<int,int>

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n < 2)
            return vector<int>(n,0);
        
        vector<Pair>V;
        int i;
        for(i=0;i<n;i++)
            V.push_back(Pair(nums[i],i));
        
        vector<int>C(n,0);
        mergeSort(V,C);
        
        // for(i=0;i!=n;i++)
        //     cout<<V[i].first<<' ';
        
        return C;
    }
    
    void mergeSort(vector<Pair>&V,vector<int>&C)
    {
        if(V.size() == 1)
            return;
        
        vector<Pair>L,R;
        int i,j,k,n,m;
        n = V.size();
        m = (n-1)/2;
        
        for(i=0;i!=m+1;i++)
            L.push_back(V[i]);
        
        mergeSort(L,C);
        
        for(i=m+1;i<n;i++)
            R.push_back(V[i]);
        
        mergeSort(R,C);
        
//         cout<<"\nLeft:\n";
//         for(i=0;i!=L.size();i++)
//             cout<<L[i].first<<' ';

//         cout<<"\nRight:\n";
//         for(i=0;i!=R.size();i++)
//             cout<<R[i].first<<' ';

        
        
        i = j = k = 0;
        while(i < m+1 && j < n-m-1)
        {
            if(L[i].first <= R[j].first)
            {
                C[L[i].second] += k-i;
                V[k] = L[i];
                i++;
                k++;
            }
            else
            {
                V[k] = R[j];
                j++;
                k++;
            }
        }
        
        while(i < m+1)
        {
            C[L[i].second] += k-i;
            V[k] = L[i];
            k++;
            i++;
        }
        
        while(j < n-m-1)
        {
            V[k] = R[j];
            j++;
            k++;
        }
        
//         for(i=0;i!=V.size();i++)
//             cout<<V[i].first<<' ';
        
//         cout<<'\n';
    }
};
