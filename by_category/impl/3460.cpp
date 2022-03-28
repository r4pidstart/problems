// https://www.acmicpc.net/problem/3460
// 2022-03-29 00:57:33 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        bitset<40> b(n);
        for(int i=0; i<40; i++)
            if(b[i]) printf("%d ", i);
        printf("\n");
    }
}

/*
    
*/