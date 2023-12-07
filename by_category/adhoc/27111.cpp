// https://www.acmicpc.net/problem/27111
// 2023-12-07 23:49:24
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(200001);

    int cnt=0;
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        if((arr[a] ^ b) == 0) cnt++;
        arr[a]=b;
    }
    printf("%d", cnt + accumulate(arr.begin(), arr.end(), 0));
}

/*
    
*/