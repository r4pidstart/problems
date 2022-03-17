// https://www.acmicpc.net/problem/1977
// 2022-03-17 15:16:11 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    int min_square=INT32_MAX, sum=0;

    for(int i=n; i<=m; i++)
    {
        if((int)sqrt(i)*(int)sqrt(i) == i)
            min_square=min(min_square, i), sum+=i;
    }

    if(!sum) printf("-1");
    else printf("%d\n%d", sum, min_square);
}

/*
    
*/