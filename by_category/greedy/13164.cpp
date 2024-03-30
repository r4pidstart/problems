// https://www.acmicpc.net/problem/13164
// 2024-03-29 22:20:35
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n, k; scanf("%d%d", &n, &k);
    vector<long> arr(n);
    for(int i=0; i<n; i++)
        scanf("%ld", &arr[i]);
    
    vector<long> dif(n);
    for(int i=0; i<n-1; i++)
        dif.push_back(abs(arr[i]-arr[i+1]));

    sort(dif.begin(), dif.end(), greater<>());
    printf("%ld", accumulate(dif.begin()+k-1, dif.end(), 0L));
}

/*
    
*/