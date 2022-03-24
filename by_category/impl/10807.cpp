// https://www.acmicpc.net/problem/10807
// 2022-03-25 00:23:39 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int target; scanf("%d", &target);
    printf("%d", count(arr.begin(), arr.end(), target));
}

/*
    
*/