// https://www.acmicpc.net/problem/1297
// 2022-03-30 23:52:45 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int d, h, w;
    scanf("%d%d%d", &d, &h, &w);
    printf("%d %d", (int)(sqrt(((double)d*d / (h*h + w*w)))*h), (int)(sqrt(((double)d*d / (h*h + w*w)))*w));
}

/*
    (h*h + w*w) * k*k = d*d
    -> d*d / (h*h + w*w) = k*k
*/