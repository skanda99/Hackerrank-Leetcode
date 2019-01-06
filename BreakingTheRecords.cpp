
// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem

#include <iostream>

using namespace std;


int main() 
{
    long int largest,smallest,n,S[1000];
    cin >> n;
    
    int countH=0,countL=0;
    
    for(int i=0;i<n;i++)
        cin>>S[i];
    
    largest=S[0];
    smallest=S[0];
    
    for(int i=1;i<n;i++)
        if(largest<S[i])
        {
             largest=S[i];
             countH++;
        }
    
     for(int i=1;i<n;i++)
         if(smallest>S[i])
         {
             smallest=S[i];
             countL++;
         }
    
     cout<<countH<<" "<<countL;
    
    
    
    return 0;
}
