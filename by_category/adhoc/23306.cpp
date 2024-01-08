// https://www.acmicpc.net/problem/23306
// 2024-01-07 12:26:58
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    setbuf(stdout, nullptr);
    printf("? 1\n");
    int a; scanf("%d", &a);
    printf("? %d\n", n);
    int b; scanf("%d", &b);

    if(a==0 and b==1) printf("! 1\n");
    else if(a==1 and b==0) printf("! -1\n");
    else printf("! 0\n");
}

/*
    
*/