// https://www.acmicpc.net/problem/26071
// 2023-05-11 22:27:39
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int max_x=0, min_x=INT32_MAX, max_y=0, min_y=INT32_MAX;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            char a; scanf(" %c", &a);
            if(a=='G')
            {
                max_x=max(max_x, i), min_x=min(min_x, i);
                max_y=max(max_y, j), min_y=min(min_y, j);
            }
        }

    if(max_x == min_x) max_x=0;
    if(max_y == min_y) max_y=0;
    printf("%d", min(max_x, n-min_x-1) + min(max_y, n-min_y-1));
}

/*
    
*/