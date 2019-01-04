
// problem: "https://www.hackerrank.com/challenges/birthday-cake-candles/problem"


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main()
{
    long unsigned int count=0,array[100000],num,choice;
    cin>>num;
    for(int i=0;i<num;i++)
        cin>>array[i];
    
    choice=array[0];
    count=1;
    
    for(int i=1;i<num;i++)
    {
         
        if (choice==array[i])
            count++;
        if (choice<array[i])
        {
            choice=array[i];
            count=1;
        }
    }
    
    cout<<count;
    return 0;
}