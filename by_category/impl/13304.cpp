// https://www.acmicpc.net/problem/13304
// 2023-04-23 09:12:22
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    int first=0, second_m=0, second_f=0, third_m=0, third_f=0l;
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        if(b<=2) first++;
        else if(b<=4 and a==0) second_m++;
        else if(b<=4) second_f++;
        else if(b<=6 and a==0) third_m++;
        else third_f++;
    }

    int ans=0;
    if(first) ans+=(first-1+k)/k;
    if(second_m) ans+=(second_m-1+k)/k;
    if(second_f) ans+=(second_f-1+k)/k;
    if(third_m) ans+=(third_m-1+k)/k;
    if(third_f) ans+=(third_f-1+k)/k;
    printf("%d", ans);
}

/*
    
*/