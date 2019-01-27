
// problem: "https://www.hackerrank.com/challenges/3d-surface-area/problem"

#include<iostream>

using namespace std;

int main()
{
    int H,W,i,j,A[101][101];
    
    cin>>H>>W;
    
    for(i=0;i<=W;i++)
        A[0][i]=0;
    
    for(i=0;i<=H;i++)
        A[i][0]=0;
    
    for(i=1;i<=H;i++)
        for(j=1;j<=W;j++)
            cin>>A[i][j];
    
    int S=0;
    for(i=1;i<=H;i++)
        for(j=1;j<=W;j++)
            S = S + 4*A[i][j] + 2 - 2*(min(A[i][j],A[i][j-1])+min(A[i][j],A[i-1][j]));
    
    cout<<S;
    
    return 0;
}