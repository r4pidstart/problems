// https://www.acmicpc.net/problem/28295
// 2023-07-04 01:38:05
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    const char* dir[4]={"N", "E", "S", "W"};
    int d=0;
    for(int i=0; i<10; i++)
    {
        int c; scanf("%d", &c);
        d+=c;
    }
    printf("%s", dir[d%4]);
}

/*
    
*/