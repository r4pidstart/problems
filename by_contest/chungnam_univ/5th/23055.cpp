// https://www.acmicpc.net/problem/23055
// 2021-11-13 00:01:55 A
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if(i==0 or j==0 or i==n-1 or j==n-1 or i==j or i==n-j-1) printf("*");
            else printf(" ");
        printf("\n");
    }
}

/*
    
*/