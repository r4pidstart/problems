// https://www.acmicpc.net/problem/18511    
// 2023-06-01 02:57:17
#include"bits/stdc++.h"
using namespace std;

int solution(int now, vector<int>& arr, int n)
{
    if(now > n) return 0;

    int ret=now;
    for(auto i : arr)
        ret=max(ret, solution(now*10+i, arr, n));
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d", &n,&k);
    vector<int> arr(k);
    for(int i=0; i<k; i++)
        scanf("%d", &arr[i]);
    
    printf("%d", solution(0, arr, n));
}

/*
    
*/