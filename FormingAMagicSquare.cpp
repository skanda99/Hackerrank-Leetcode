
// problem: "https://www.hackerrank.com/challenges/magic-square-forming/problem"

#include <bits/stdc++.h>
#include<math.h>

using namespace std;

int main()
{
    int G[3][3],i,j,sum[8],min;
    
    
    int A[3][3]={8,1,6,3,5,7,4,9,2};
    int B[3][3]={4,3,8,9,5,1,2,7,6};
    int C[3][3]={2,9,4,7,5,3,6,1,8};
    int D[3][3]={6,7,2,1,5,9,8,3,4};
    int E[3][3]={6,1,8,7,5,3,2,9,4};
    int F[3][3]={8,3,4,1,5,9,6,7,2};
    int H[3][3]={4,9,2,3,5,7,8,1,6};
    int I[3][3]={2,7,6,9,5,1,4,3,8};
    
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
             cin>>G[i][j];
        
    for(i=0;i<8;i++)
        sum[i]=0;
        
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
             sum[0]=sum[0]+abs(A[i][j]-G[i][j]);
             sum[1]=sum[1]+abs(B[i][j]-G[i][j]);
             sum[2]=sum[2]+abs(C[i][j]-G[i][j]);
             sum[3]=sum[3]+abs(D[i][j]-G[i][j]);
             sum[4]=sum[4]+abs(E[i][j]-G[i][j]);
             sum[5]=sum[5]+abs(F[i][j]-G[i][j]);
             sum[6]=sum[6]+abs(H[i][j]-G[i][j]);
             sum[7]=sum[7]+abs(I[i][j]-G[i][j]);
        }
    
    
    min=sum[0]; 
    for(i=1;i<8;i++)
        if(min>sum[i])
            min=sum[i];
                
    cout<<min;
        
        
    return 0;    
        
}

