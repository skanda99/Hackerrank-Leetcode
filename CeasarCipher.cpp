
// problem: "https://www.hackerrank.com/challenges/caesar-cipher-1/problem"

#include<iostream>

using namespace std;

int main()
{
    char string[100];
    int i,size,K,x,y;

    cin>>size;
    cin>>string;
    cin>>K;

    for(i=0;i<size;i++)
    {
        if(isalpha(string[i]))
        {
            if(isupper(string[i]))
            {
                x=K%26;
                if(x+(int)(string[i])<91)
                    cout<<(char)(x+(int)(string[i]));
                else
                {
                    y=x-(91-(int)(string[i]));
                    cout<<(char)(y+65);
                }
            }
            else
            {
                x=K%26;
                if(x+(int)(string[i])<123)
                    cout<<(char)(x+(int)(string[i]));
                else
                {
                    y=x-(123-(int)(string[i]));
                    cout<<(char)(y+97);
                }
            }
        }
        else
            cout<<string[i];
    }

    return 0;
}
