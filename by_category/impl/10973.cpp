// https://www.acmicpc.net/problem/10973
// 2022-03-26 07:27:32 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    if(prev_permutation(arr.begin(), arr.end()))
        for(auto i : arr) printf("%d ", i);
    else
        printf("-1");
}

/*
    
*/