// https://www.acmicpc.net/problem/10707
// 2022-03-28 23:26:40 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b,c,d,p; scanf("%d%d%d%d%d", &a, &b, &c, &d, &p);
    printf("%d", min(p*a, b+(p <= c ? 0 : (p-c)*d)));
}

/*
    
*/