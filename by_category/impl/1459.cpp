// https://www.acmicpc.net/problem/1459
// 2023-02-20 04:01:21
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    long x,y,w,s; scanf("%ld%ld%ld%ld", &x, &y, &w, &s);
    printf("%ld", min({min(x,y)*s + (max(x,y)-min(x,y))*w, 
                        (x+y)*w, 
                        min(x,y)*s + (max(x,y)-min(x,y))*s + ((max(x,y)-min(x,y))&1)*w - ((max(x,y)-min(x,y))&1)*s}));
}

/*
    
*/