
// problem: "https://www.hackerrank.com/challenges/cats-and-a-mouse/problem"

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i,q,x[100],y[100],z[100];
    
    cin>>q;
    for(i=0;i<q;i++)
        cin>>x[i]>>y[i]>>z[i];
    
    for(i=0;i<q;i++)
    {
        if(abs(x[i]-z[i])<abs(y[i]-z[i]))
            cout<<"Cat A"<<endl;
        
        else if(abs(x[i]-z[i])>abs(y[i]-z[i]))
            cout<<"Cat B"<<endl;
        
        else
            cout<<"Mouse C"<<endl;
                    
    }
    
    return 0;
}