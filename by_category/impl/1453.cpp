// https://www.acmicpc.net/problem/1453
// 2022-04-03 17:10:04 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(101);
    int ans=0;
    while(n--)
    {
        int a; scanf("%d", &a);
        if(arr[a]) ans++;
        arr[a]=1;
    }
    printf("%d", ans);
}

/*
    
*/