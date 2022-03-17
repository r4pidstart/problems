// https://www.acmicpc.net/problem/10992
// 2022-03-17 20:34:46 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        // space
        for(int j=0; j<n-i-1; j++) printf(" ");
        // star
        if(i) printf("*");
        // fill
        for(int j=0; j<2*i-1; j++)
            printf("%c", (i==n-1) ? '*':' ');
        printf("*\n");
    }
}

/*
    
*/