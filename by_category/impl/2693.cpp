// https://www.acmicpc.net/problem/2693
// 2022-03-26 07:34:26 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        vector<int> arr(10);
        for(int i=0; i<10; i++)
            scanf("%d", &arr[i]);
        sort(arr.begin(), arr.end());
        printf("%d\n", arr[7]);
    }
}

/*
    
*/