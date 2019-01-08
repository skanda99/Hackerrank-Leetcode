
// problem: "https://www.hackerrank.com/challenges/counting-valleys/problem"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    long int n;
    char ch[1000000];
    cin>>n;
    
    for(int i=0;i<n;i++)
        cin>>ch[i];
    
    int countU=0,countD=0,countV=0;
    
    for(int j=0;j<n;j++)
    {
        if(ch[j]=='U')
            countU++;
        
        if(ch[j]=='D')
            countD++;
        
        //if(countD>countU)
          //  
        
        if(countD==countU)
        {
            if(ch[j]=='U')
            {
                countV++;
            }    
            
            countU=countD=0;
            
        }
    }
    
    
    cout<<countV;
    
    return 0;
}
