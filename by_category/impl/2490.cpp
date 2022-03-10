// https://www.acmicpc.net/problem/2490
// 2022-03-11 03:04:16 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    array<int, 4> arr;
    while(scanf("%d", &arr[0]) != EOF)
    {
        for(int i=1; i<4; i++) scanf("%d", &arr[i]);
        switch (accumulate(arr.begin(), arr.end(), 0))
        {
        case 0:
            printf("D\n");
            break;
        case 1:
            printf("C\n");
            break;
        case 2:
            printf("B\n");
            break;
        case 3:
            printf("A\n");
            break;
        case 4:
            printf("E\n");
            break;
        }
    }
}

/*
    
*/