// https://www.acmicpc.net/problem/11728
// 2022-03-22 21:56:44 912ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n+m);
    for(int i=0; i<arr.size(); i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    for(auto i : arr)
        printf("%d ", i);
}

/*
    
*/