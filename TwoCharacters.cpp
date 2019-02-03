
// problem: "https://www.hackerrank.com/challenges/two-characters/problem"

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int isAltern(string &s,char c1,char c2)
{
    int i,N;
    char p;
    for(i=0;i!=s.size();i++)
        if(s[i] == c1 || s[i] == c2)
        {
            p = s[i];
            break;
        }

    N = 1;
    for(i=i+1;i!=s.size();i++)
    {
        if(s[i]==c1 || s[i]==c2)
        {
            if(s[i]==p)
                return 0;

            p = s[i];
            N++;
        }
    }

    return N;
}

int main()
{
    int N;
    string s;

    cin>>N>>s;

    vector<char>C;
    vector<int>A(26);

    int i,j;
    for(i=0;i!=N;i++)
    {
        if(A[(int)s[i]-97]==0)
        {
            A[(int)s[i]-97] = 1;
            C.push_back(s[i]);
        }
    }

    int Max = 0;
    for(i=0;i!=C.size()-1;i++)
    {
        for(j=i+1;j!=C.size();j++)
        {
            Max = max(Max,isAltern(s,C[i],C[j]));       // define function
        }
    }

    cout<<Max;

    return 0;
}
