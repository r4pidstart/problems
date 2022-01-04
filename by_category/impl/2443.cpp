// https://www.acmicpc.net/problem/2443
// 2022-01-05 05:54:50 
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++) printf(" ");
        for(int j=0; j<2*n-1-2*i; j++) printf("*");
        printf("\n");
    }
}

/*
    
*/