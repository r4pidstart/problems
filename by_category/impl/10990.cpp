// https://www.acmicpc.net/problem/10990
// 2022-03-25 00:42:36 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++) printf(" ");
        if(i) printf("*");
        for(int j=0; j<i*2-1; j++) printf(" ");
        printf("*\n");
    }
}

/*
    
*/