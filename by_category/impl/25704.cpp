// https://www.acmicpc.net/problem/25704
// 2022-10-14 05:42:08
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,p; scanf("%d%d", &n, &p);
    int ans=p;
    if(n>=5) ans=min(ans, p-500);
    if(n>=10) ans=min(ans, (int)(p*0.9));
    if(n>=15) ans=min(ans, p-2000);
    if(n>=20) ans=min(ans, (int)(p*0.75));
    printf("%d", max(0, ans));
}

/*
    
*/