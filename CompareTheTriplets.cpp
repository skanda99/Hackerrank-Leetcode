
// Problem: "https://www.hackerrank.com/challenges/compare-the-triplets/problem"

#include<iostream>

using namespace std;

int main()  
{
    int alice[3],bob[3],a,b;
    a=b=0;
    cin>>alice[0]>>alice[1]>>alice[2];
    cin>>bob[0]>>bob[1]>>bob[2];
    
    for(int i=0;i<3;i++)
        {if(alice[i]>bob[i])
            a++;
         else if(alice[i]<bob[i])
            b++;
             else
                 continue;
        }
    cout<<a<<" "<<b;
    return 0;
        
}
