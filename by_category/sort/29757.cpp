// https://www.acmicpc.net/problem/29757
// 2023-12-01 23:10:22
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<tuple<int,int,int> > arr;
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        arr.push_back({a, b, i});
    }

    sort(arr.begin(), arr.end());

    for(int i=1; i<n; i++)
        printf("%d %d\n", get<2>(arr[i-1])+1, get<2>(arr[i])+1);
}

/*
    
*/