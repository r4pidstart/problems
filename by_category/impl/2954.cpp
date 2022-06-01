// https://www.acmicpc.net/problem/2954
// 2022-06-02 02:44:31 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    char c;
    while(scanf("%c", &c) != EOF)
    {
        printf("%c", c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            scanf("%c", &c), scanf("%c", &c);
    }
}

/*
    
*/