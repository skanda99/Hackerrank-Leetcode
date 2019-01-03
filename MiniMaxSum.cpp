
// problem: "https://www.hackerrank.com/challenges/mini-max-sum/problem"

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


int main(){
    long long unsigned int array[5],max,min,sum;
    int i;
    sum=0;
    
    for(i=0;i<5;i++)
    cin>>array[i];
    
    min=max=array[0];
    for(i=0;i<5;i++)
    {
        sum=sum+array[i];
        
        if(max<array[i])
            max=array[i];
        
        if(min>array[i])
            min=array[i];
    }
    
    cout<<sum-max<<" "<<sum-min;
    
    return 0;
}
