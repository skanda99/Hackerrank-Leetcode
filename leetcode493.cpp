
// problem: "https://leetcode.com/problems/reverse-pairs/"

#define ll long long

class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);      
    }
    
    int reversePairs(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int count = 0;
        mergeSort(nums,count);
        
        return count;
    }
    
    void mergeSort(vector<int>&V,int &count)
    {
        if(V.size() == 1)
            return;
        
        int l = 0;
        int r = V.size()-1;
        int m = (l+r)/2;
        
        vector<int>L,R;
        int i,j,k;
        
        for(i=0;i!=m+1;i++)
            L.push_back(V[i]);
        
        mergeSort(L,count);
        
        for(i=m+1;i!=r+1;i++)
            R.push_back(V[i]);
        
        mergeSort(R,count);
        
        i = j = k = 0;
        while(i < m+1 && j < r-m)
        {
            if(L[i] < R[j])
            {
                V[k] = L[i];
                i++;
                k++;
            }
            else
            {
                count += countGreater(L,0,m,2*(ll)R[j]);
                V[k] = R[j];
                j++;
                k++;
            }
        }
        
        while(i < m+1)
        {
            V[k] = L[i];
            i++;
            k++;
        }
        
        while(j < r-m)
        {
            count += countGreater(L,0,m,2*(ll)R[j]);   
            V[k] = R[j];
            j++;
            k++;
        }
    }
    
    int countGreater(vector<int>&V,int i,int j,ll k)
    {
        int count = 0;
        int n = V.size();
        while(i <= j)
        {
            int m = (i+j)/2;
            
            if(V[m] <= k)
                i = m+1;
            else
            {
                count = max(count,n-m);
                j = m-1;
            }
        }
        
        return count;
    }
};
