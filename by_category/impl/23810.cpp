// https://www.acmicpc.net/problem/23810
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("@@@@@");
        printf("\n");
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("@");
        printf("\n");
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("@@@@@");
        printf("\n");
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("@");
        printf("\n");
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("@");
        printf("\n");
    }
}   

/*
@@@@@
@
@@@@@
@
@
*/