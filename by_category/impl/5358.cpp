// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    char c;
    while(~scanf("%c", &c))
    {
        if(c=='i') printf("e");
        else if(c=='e') printf("i");
        else if(c=='I') printf("E");
        else if(c=='E') printf("I");
        else printf("%c", c);
    }
}

/*
    
*/