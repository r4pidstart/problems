// https://www.acmicpc.net/problem/10813
// 2023-02-27 02:55:25
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        swap(arr[a-1], arr[b-1]);
    }

    for(auto i : arr)
        printf("%d ", i);
}

/*
    
*/