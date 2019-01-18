
// problem: "https://www.hackerrank.com/challenges/taum-and-bday/problem"

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int T,i;
    unsigned long int B,W,X,Y,Z;
    
    cin>>T;
    
    for(i=0;i<T;i++)
    {
        cin>>B>>W;
        cin>>X>>Y>>Z;
        
        if(X<Y)
            cout<<(B*X)+(W*min(Y,X+Z))<<endl;
        
        else
            cout<<(W*Y)+(B*min(X,Y+Z))<<endl;
    }
    
    return 0;
}