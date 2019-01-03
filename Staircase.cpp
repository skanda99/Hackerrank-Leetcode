
// problem: "https://www.hackerrank.com/challenges/staircase/problem"

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    int size;
    cin>>size;
    for(int i=1;i<=size;i++)
        {
        cout<<setw(size-i+1);
        for(int j=1;j<=i;j++)
        cout<<"#";
        cout<<endl;
        }
    return 0;
}
