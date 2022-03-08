// https://www.acmicpc.net/problem/2920
// 2022-03-08 19:19:29 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    array<int, 8> arr;
    for(int i=0; i<8; i++)
        scanf("%d", &arr[i]);
    
    int prev=arr[0];
    for(int i=1; i<8; i++)
        if(prev > arr[i])
            prev=arr[i];
        else
            break;
    
    if(prev==arr[7])
        return !printf("descending");
    
    prev=arr[0];
    for(int i=1; i<8; i++)
        if(prev < arr[i])
            prev=arr[i];
        else
            break;
    
    if(prev==arr[7])
        return !printf("ascending");
    
    printf("mixed");
}

/*
    
*/