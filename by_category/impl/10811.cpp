// https://www.acmicpc.net/problem/10811
// 2023-02-27 02:57:05
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
        reverse(arr.begin()+a-1, arr.begin()+b);
    }

    for(auto i : arr)
        printf("%d ", i);
}

/*
    
*/