// https://www.acmicpc.net/problem/20937
// 2023-12-21 01:09:10
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> cnt(50001);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        cnt[a]++;
    }
    printf("%d", *max_element(cnt.begin(), cnt.end()));
}

/*
    
*/