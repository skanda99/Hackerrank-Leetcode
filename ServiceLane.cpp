
// problem: "https://www.hackerrank.com/challenges/service-lane/problem"

#include<iostream>

using namespace std;

int main()
{
    long int N,i,j,I,J;
    int T,width[100000],min;
    
    cin>>N>>T;
    
    for(i=0;i<N;i++)
        cin>>width[i];
    
    for(i=0;i<T;i++)
    {
        cin>>I>>J;
        
        min=width[I];
        for(j=I;j<=J;j++)
        {
            if(min>width[j])
                min=width[j];            
        }
        
        cout<<min<<endl;
    }
    
    return 0;    
}