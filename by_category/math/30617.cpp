// https://www.acmicpc.net/problem/30617
// 2023-11-17 00:02:50
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    int score=0;
    int a=-100, b=-100;
    for(int i=0; i<t; i++)
    {
        int c,d; scanf("%d%d", &c, &d);
        if(c and a==c) score++;
        if(d and b==d) score++;
        if(c and c==d) score++;
        a=c, b=d;
    }
    printf("%d", score);
}

/*
    
*/