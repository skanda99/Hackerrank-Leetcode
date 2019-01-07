
// problem: "https://www.hackerrank.com/challenges/migratory-birds/problem"

#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n,type,c1, c2,c3,c4,c5;
    c1=c2=c3=c4=c5=0;
    
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
         cin>>type;
         switch(type)
         {
             case 1 : c1++; break;
             case 2 : c2++; break;
             case 3 : c3++; break;
             case 4 : c4++; break;
             case 5 : c5++; break;
         }    
    }
    
    int largest,t,count[5];
    count[0]=c1;
    count[1]=c2;
    count[2]=c3;
    count[3]=c4;
    count[4]=c5;
    
    largest=count[0];
    
    for(int i=4;i>=0;i--)
    {   
        if(largest<=count[i])
        {
             largest=count[i];
             t=i;
        }
            
    }
    
    cout<<t+1;
    
    return 0;
}
