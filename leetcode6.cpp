
// problem: "https://leetcode.com/problems/zigzag-conversion/"

class Solution {
public:
    string convert(string A, int B) {

        if(B == 1)
        return A;

    vector<string>V(B);
    int i,j;

    j = 0;
    i = 0;
    while(i<A.size())
    {
        if(i==0)
            j = 0;

        else
            j = 1;

        while(j < B && i < A.size())
        {
            V[j].append(A.substr(i,1));
            j++;
            i++;
        }

        j = B-2;
        while(j >=0 && i < A.size())
        {
            V[j].append(A.substr(i,1));
            i++;
            j--;
        }
    }

    string s;
    for(i=0;i!=B;i++)
        s.append(V[i]);

    return s;

    }
};
