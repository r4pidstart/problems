// https://www.acmicpc.net/problem/1377
// 2024-04-21 18:58:52
#include"bits/stdc++.h"
using namespace std;

int naive(const vector<int>& arr)
{
    vector<int> A=arr;
    int N=A.size()-1;
    bool changed = false;
    for (int i=1; i<=N+1; i++) {
        changed = false;
        for (int j=1; j<=N-i; j++) {
            if (A[j] > A[j+1]) {
                changed = true;
                swap(A[j], A[j+1]);
            }
        }
        if (changed == false) {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int, int> > arr(n+1);
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i].first), arr[i].second=i;

    vector<pair<int, int> > sorted(arr);
    sort(sorted.begin(), sorted.end());

    int ans=0;
    for(int i=1; i<=n; i++)
        ans=max(ans, sorted[i].second-i);

    printf("%d\n", ans+1);
#ifdef LOCAL
    // printf("\nexpected: %d\n", naive(arr));
    // assert(naive(arr) == ans);
#endif
}

/*

*/