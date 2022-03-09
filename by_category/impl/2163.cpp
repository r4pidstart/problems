// https://www.acmicpc.net/problem/2163
// 2022-03-09 19:21:44 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b; scanf("%d%d", &a,&b);
    printf("%d", (min(a,b)-1) + (min(a,b)) * (max(a,b)-1));
}
