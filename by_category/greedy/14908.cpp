// https://www.acmicpc.net/problem/14908
// 2024-04-23 23:26:21
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);

    vector<tuple<int, int, int> > arr(n);
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        arr[i]={a, b, i+1};
    }

    stable_sort(arr.begin(), arr.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<0>(a)*get<1>(b) < get<0>(b)*get<1>(a);
    });
    for(auto [a,b,c] : arr)
        printf("%d ", c);
}

/*

*/