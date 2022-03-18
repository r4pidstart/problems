// https://www.acmicpc.net/problem/2953
// 2022-03-18 23:34:29 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int>arr(4); int anssum=0, ans=0;
    for(int i=1; i<=5; i++)
    {
        for(int j=0; j<4; j++)
            scanf("%d", &arr[j]);
        if(accumulate(arr.begin(), arr.end(), 0) > anssum)
            anssum=accumulate(arr.begin(), arr.end(), 0), ans=i;
    }
    printf("%d %d", ans, anssum);
}

