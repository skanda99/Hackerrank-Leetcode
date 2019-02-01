
// problem: "https://www.hackerrank.com/challenges/tutorial-intro/problem"

#include<stdio.h>

int main()
{
    int i,v,n,a[1000];

    scanf(" %d %d",&v,&n);
    for(i=0;i<n;i++)
        scanf(" %d",&a[i]);

    for(i=0;i<n;i++)
        if(a[i]==v)
        {
            printf("%d",i);
            break;
        }
    return 0;
}
