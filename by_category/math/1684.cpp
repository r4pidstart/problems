// https://www.acmicpc.net/problem/1684
// 2024-05-28 23:48:34
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    int ans=arr[1]-arr[0];
    for(int i=1; i<n; i++)
        ans=gcd(ans, arr[i]-arr[i-1]);
    cout << ans;
}

/*

*/