// https://www.acmicpc.net/problem/17608
// 2022-04-25 17:13:43 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int m=0, cnt=0;
    vector<int> arr;
    while(n--)
    {
        int a; scanf("%d", &a);
        arr.push_back(a);
    }
    reverse(arr.begin(), arr.end());
    for(auto a : arr)
        if(a > m) cnt++, m=a;
    printf("%d", cnt);
}

/*
    
*/