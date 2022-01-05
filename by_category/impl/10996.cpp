// https://www.acmicpc.net/problem/10996
// 2022-01-06 00:56:26 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if(j&1) printf(" ");
            else printf("*");
        printf("\n");
        for(int j=0; j<n; j++) 
            if(j&1) printf("*");
            else printf(" ");
        printf("\n");
    }
}

/*
    
*/