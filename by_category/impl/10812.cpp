// https://www.acmicpc.net/problem/10812
// 2023-03-13 23:50:20  
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    while(m--)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        vector<int> tmp(arr.begin()+a-1, arr.begin()+b);
        for(int i=a-1; i<b; i++)
            arr[i]=tmp[(i+c-2*a+1)%tmp.size()];
    }
    for(auto i : arr)
        printf("%d ", i);
}

/*
    
*/