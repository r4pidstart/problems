// https://www.acmicpc.net/problem/14729
// 2022-05-03 00:08:21 3124ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<float> arr(n);
    for(int i=0; i<n; i++)
        scanf("%f", &arr[i]);
    sort(arr.begin(), arr.end());
    for(int i=0; i<7; i++)
        printf("%.3f\n", arr[i]);
}

/*
    
*/