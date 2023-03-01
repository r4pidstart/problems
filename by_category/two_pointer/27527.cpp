// https://www.acmicpc.net/problem/27527
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    int target_cnt=ceil(9.*m/10);
    
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    vector<int> cnt(1e6+1);
    for(int i=0; i<n; i++)
    {
        if(i>=m)
            cnt[arr[i-m]]--;
        cnt[arr[i]]++;
        if(cnt[arr[i]] == target_cnt)
            return !printf("YES");
    }
    printf("NO");
}

/*
    
*/