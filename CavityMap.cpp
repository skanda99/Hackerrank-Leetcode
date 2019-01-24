
// problem: "https://www.hackerrank.com/challenges/cavity-map/problem"

#include<iostream>

using namespace std;

int main()
{
    long int n,i,j;
    char A[100][100];
    
    cin>>n;
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>A[i][j];
    
    for(i=1;i<n-1;i++)
        for(j=1;j<n-1;j++)
        {
            if((A[i][j]<=A[i-1][j])||(A[i-1][j]=='X'))
                continue;
            
            if((A[i][j]<=A[i][j-1])||(A[i][j-1]=='X'))
                continue;
            
            if((A[i][j]<=A[i+1][j])||(A[i+1][j]=='X'))
                continue;
            
            if((A[i][j]<=A[i][j+1])||(A[i][j+1]=='X'))
                continue;
            
            A[i][j]='X';
        }
   
    
     for(i=0;i<n;i++)
     {   
         for(j=0;j<n;j++)
            cout<<A[i][j];
         
         cout<<endl;
     }    
           
    return 0;
}
