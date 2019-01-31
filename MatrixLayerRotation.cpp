
// problem: "https://www.hackerrank.com/challenges/matrix-rotation-algo/problem"

#include<iostream>
#include<math.h>

using namespace std;

void rotate (long long int a[300][300],long long int b[300][300],int i,int j,int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4,int R)
{
    int z,I,J;
    
    I=i;    J=j;
        
    for(z=0;z<R;z++)
    {
        if((i==x1)&&(j-1>=y1))
            j=j-1;
        else if((i==x1)&&(j==y1))
            i=i+1;
        else if((j==y1)&&(i+1<=x4))
            i=i+1;
        else if((j==y1)&&(i==x4))
            j=j+1;
        else if((j+1<=y3)&&(i==x4))
            j=j+1;
        else if((i==x4)&&(j==y3))
            i=i-1;
        else if((i-1>=x2)&&(j==y2))
            i=i-1;
        else
            j=j-1;
    }
    
    b[i][j]=a[I][J];
}

int main()
{
    long long int R,A[300][300],B[300][300];
    int r,x1,x2,x3,x4,y1,y2,y3,y4,i,j,t,n,M,N;
    
    cin>>M>>N>>R;
    
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
            cin>>A[i][j];
    
    n=min(M,N)/2;                                         //n is max nmber of rectangles
    
    for(i=0;i<n;i++)
    {
        x1=i;      y1=i;
        x2=x1;     y2=N-1-i;
        x3=M-1-i;  y3=y2;
        x4=x3;     y4=y1;
        
        t=2*(x4-x1+y2-y1);
        r=R%t;
        
        for(j=x1;j<=x4;j++)
        {
            rotate(A,B,j,y1,x1,x2,x3,x4,y1,y2,y3,y4,r);
            rotate(A,B,j,y2,x1,x2,x3,x4,y1,y2,y3,y4,r);
        }
        
        for(j=y1+1;j<y3;j++)
        {
            rotate(A,B,x4,j,x1,x2,x3,x4,y1,y2,y3,y4,r);
            rotate(A,B,x1,j,x1,x2,x3,x4,y1,y2,y3,y4,r);
        }
    }
    
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
            cout<<B[i][j]<<" ";
        
        cout<<endl;
    }
    
    
    return 0;
}