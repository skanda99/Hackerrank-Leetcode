
// problem: "https://leetcode.com/problems/trapping-rain-water/"

class Solution {
public:

    int trap(vector<int>& height) {
        int n,i,j;
        n = height.size();

        if(n < 3)
            return 0;

        vector<int>Pair(n,-1);
        stack<int>S;

        for(i=0;i!=n;i++)
        {
            if(S.empty())
                S.push(i);
            else
            {
                if(height[i] < height[S.top()])
                    S.push(i);
                else
                {
                    while(!S.empty() && height[S.top()] <= height[i])
                    {
                        j = S.top();
                        S.pop();
                    }

                    if(S.empty())
                        Pair[j] = i;
                    else
                        Pair[S.top()] = i;

                    S.push(i);
                }
            }
        }

        int sum = 0;
        i = 0;
        while(i < n)
        {
            if(Pair[i] == -1)
            {
                i++;
                continue;
            }

            j = Pair[i];
            sum += (j-i-1) * min(height[i],height[j]) - sumI(i+1,j,height);     // define

            i = j;
        }

        return sum;
    }

    int sumI(int i,int n,vector<int>&height)
    {
        int sum = 0;
        for(;i<n;i++)
            sum += height[i];

        return sum;
    }
};
