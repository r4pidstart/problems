// https://www.acmicpc.net/problem/30394
// 2023-11-04 00:27:32
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n);
    int trash;
    for(int i=0; i<n; i++)
        scanf("%d%d", &trash, &arr[i]);
    
    printf("%d", *max_element(arr.begin(), arr.end())-*min_element(arr.begin(), arr.end()));
}

/*
    
*/