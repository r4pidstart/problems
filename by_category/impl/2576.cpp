// https://www.acmicpc.net/problem/2576
// 2022-03-17 15:01:29 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> arr(7);
    for(int i=0; i<7; i++)
        scanf("%d", &arr[i]);

    int ans=0;
    int min_odd=INT32_MAX;
    for(int i : arr)
        if(i&1) ans+=i, min_odd=min(min_odd, i);
    
    if(!ans) printf("-1");
    else printf("%d\n%d", ans, min_odd);
}

/*
    
*/