
// problem: "https://www.hackerrank.com/challenges/kaprekar-numbers/problem"

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    unsigned long int n,p,q,i,l,x,w;
    int d,nd;
    
    cin>>p>>q;
    
    n=0;
    
    for(i=p;i<q+1;i++)
    {
        d=0;
        x=i;
        while(x>0)
        {
            d++;
            x=x/10;
        }
        
        l=pow(i,2);
        
        x=l;
        
        for(nd=0;nd<d;nd++)
        {
            x=x/10;
        }
        w=l-(x*pow(10,d));
        if(w+x==i)
        {
            cout<<i<<" ";
            n++;
        }
    }
    
    if(n==0)
        cout<<"INVALID RANGE";
    
    return 0;
}