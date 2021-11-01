// https://www.acmicpc.net/problem/17950
// 2021-10-31 00:42:32 108ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int h,x; scanf("%d%d", &h, &x);
    // 역순으로 누적합

    vector<int> arr(h);
    for(int i=0; i<h; i++) scanf("%d", &arr[i]);

    long long ans=0;
    for(auto it=arr.rbegin(); it!=arr.rend(); it++)
        ans=((ans*x)+(*it)) % (int)(1e9+7);

    printf("%lld", (ans*x)%(int)(1e9+7));
}

/*
    4
    4*5 + 2 = 22
    22*5 + 3 = 113
    113*5 + 1 = 566
    566*5 = 2830
*/