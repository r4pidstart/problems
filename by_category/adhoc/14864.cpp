// https://www.acmicpc.net/problem/14864
// 2023-12-30 03:31:31
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    vector<int> ori=arr;
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        arr[a-1]++;
        arr[b-1]--;
    }
    vector<int> tmp=arr;
    sort(arr.begin(), arr.end());
    if(arr != ori)
        printf("-1");
    else
    {
        for(int i : tmp)
            printf("%d ", i);
    }
    
}

/*
    
*/