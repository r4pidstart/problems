// https://www.acmicpc.net/problem/5543
// 2022-03-08 19:44:42 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    array<int, 5> arr;
    for(int i=0; i<5; i++)
        scanf("%d", &arr[i]);

    printf("%d", min({(arr[0]+arr[3]), (arr[0]+arr[4]), (arr[1]+arr[3]), (arr[1]+arr[4]), (arr[2]+arr[3]), (arr[2]+arr[4])})-50);
}

/*
    
*/
