
// problem: "https://leetcode.com/problems/find-k-th-smallest-pair-distance/"

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        int l,r,m,c;
        l = 0;
        r = 1000000-1;
        int ans=0;
        
        sort(nums.begin(),nums.end());
        vector<bool>A(1000000,false);
        
        while(l <= r)
        {
            m = (l+r)/2;
            c = getNumValues(m,nums,A);           // define
            
            //cout<<c<<' '<<l<<' '<<m<<' '<<r<<'\n';
            
            if(c < k-1)
            {
                ans = m;
                l = m+1;
            }
            
            else if(c == k-1)
            {
                ans = m;
                break;
            }
            
            else
                r = m-1; 
        }
        
        while(!A[ans])
            ans++;
        
        return ans;
    }
    
    int getNumValues(int m,vector<int>&nums,vector<bool>&A)
    {
        int i,j,n,c;
        n = nums.size();
        
        c = 0;
        j = 1;
        for(i=0;i!=n-1;i++)
        {
            if(i == j)
                j++;
            
            while(j < n && nums[j]-nums[i] < m)
            {
                A[nums[j]-nums[i]] = true;
                //cout<<i<<' '<<j<<'\n';
                j++;
            }
            
            c += (j-i-1);
        }
        
        return c;
    }
};
