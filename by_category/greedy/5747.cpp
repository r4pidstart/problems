// https://www.acmicpc.net/problem/5747
// 2022-01-03 02:17:12 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    while(true)
    {
        int n; scanf("%d", &n);
        if(n==0) break;

        int maryOdd=0, maryEven=0, johnOdd=0, johnEven=0;
        for(int i=0; i<n; i++)
        {
            int tmp; scanf("%d", &tmp);
            if(tmp&1) maryOdd++;
            else maryEven++;
        }
        for(int i=0; i<n; i++)
        {
            int tmp; scanf("%d", &tmp);
            if(tmp&1) johnOdd++;
            else johnEven++;
        }

        // 짝수가 만들어지는 최소 횟수
        printf("%d\n", n - min(maryOdd, johnEven) - min(maryEven, johnOdd));
    }
}

/*
    
*/