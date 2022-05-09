// https://www.acmicpc.net/problem/10815
// 2022-03-16 00:11:40 452ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    unordered_set<int> uds;
    uds.reserve(n);

    while(n--)
    {
        int a; scanf("%d", &a);
        uds.insert(a);
    }

    scanf("%d", &n);
    while(n--)
    {
        int a; scanf("%d", &a);
        printf("%d ", uds.find(a)!=uds.end());
    }
}

/*
    
*/