// https://www.acmicpc.net/problem/30979
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t,n; scanf("%d%d", &t, &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    if(accumulate(arr.begin(), arr.end(), 0) < t)
        printf("Padaeng_i Cry");
    else
        printf("Padaeng_i Happy");
}

/*
    
*/