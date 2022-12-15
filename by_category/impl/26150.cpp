// https://www.acmicpc.net/problem/26150
// 2022-12-16 03:16:05
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<pair<int,pair<string, int> > > arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i].second.first >> arr[i].first >> arr[i].second.second;
    sort(arr.begin(), arr.end());
    for(auto i : arr)
        printf("%c", toupper(i.second.first[i.second.second-1]));
}

/*
    
*/