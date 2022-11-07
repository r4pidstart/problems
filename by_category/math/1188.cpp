// https://www.acmicpc.net/problem/1188
// 2022-11-08 03:03:32
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    printf("%d", m-gcd(n,m));
}

/*
    
*/