// problem: "https://www.hackerrank.com/challenges/plus-minus/problem"

#include<iostream>

using namespace std;

int main()
{
    int size,i,cp=0,cn=0,cz=0;
    long long int a[100];
    
    cin>>size;
    for(i=0;i<size;i++)
    {
        cin>>a[i];
        if(a[i]>0)
            cp+=1;
        else if(a[i]<0)
            cn+=1;
            else
            cz+=1;
    }
    cout<<(float)(cp)/(cp+cz+cn)<<endl;
    cout<<(float)(cn)/(cp+cz+cn)<<endl;
    cout<<(float)(cz)/(cp+cz+cn)<<endl;
    
    return 0;
    
}
