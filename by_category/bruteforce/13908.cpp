// https://www.acmicpc.net/problem/13908
// 2022-09-29 04:30:00 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    if(n==1)
        return !printf("%d", vector<int>({10, 1})[m]);
    if(n==2)
        return !printf("%d", vector<int>({100, 19, 2})[m]);
    if(n==3)
        return !printf("%d", vector<int>({1000, 271, 54, 6})[m]);
    if(n==4)
        return !printf("%d", vector<int>({10000, 3439, 974, 204, 24})[m]);
    if(n==4)
        return !printf("%d", vector<int>({10000, 3439, 974, 204, 24})[m]);
    if(n==5)
        return !printf("%d", vector<int>({100000, 40951, 14670, 4350, 960, 120})[m]);
    if(n==6)
        return !printf("%d", vector<int>({1000000, 468559, 199262, 74460, 23160, 5400, 720})[m]);
    if(n==7)
        return !printf("%d", vector<int>({10000000, 5217031, 2531214, 1119006, 436800, 142800, 35280, 5040})[m]);
}

/*
    
*/