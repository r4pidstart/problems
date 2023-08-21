// https://www.acmicpc.net/problem/28701
// 2023-08-22 03:01:16
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    long ans1=0, ans3=0;
    for(int i=1; i<=n; i++)
        ans1+=i, ans3+=i*i*i;
    printf("%ld\n%ld\n%ld", ans1, ans1*ans1, ans3);

}

/*
    
*/