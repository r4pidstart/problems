// https://www.acmicpc.net/problem/28014
// 2023-05-06 23:49:44  
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int cnt=1;
    for(int i=0; i<n; i++)
        if(i and arr[i] >= arr[i-1]) cnt++;
    printf("%d", cnt);
}

/*
    
*/