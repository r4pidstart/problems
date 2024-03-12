// https://www.acmicpc.net/problem/2892
// 2024-03-12 00:21:40
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%x", &a);
        printf("%c", a>>5 ? '-':'.');
    }
}

/*
    
*/