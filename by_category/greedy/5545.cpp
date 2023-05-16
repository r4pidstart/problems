// https://www.acmicpc.net/problem/5545
// 2023-05-16 23:34:58
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    int a,b; scanf("%d%d", &a, &b);
    int c; scanf("%d", &c);
    vector<pair<double, int> > arr(n);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        arr[i]={1.*a/b, a};
    }
    sort(arr.begin(), arr.end(), greater<>());

    int tot_cal=c, tot_price=a;
    for(int i=0; i<n; i++)
        if(arr[i].first > 1.*tot_cal/tot_price)
            tot_cal+=arr[i].second, tot_price+=b;
    printf("%d", tot_cal/tot_price);
}

/*
    
*/