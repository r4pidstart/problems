// https://www.acmicpc.net/problem/6137
// 2022-08-26 00:09:22
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<char> arr(n);
    for(int i=0; i<n; i++)
        scanf(" %c", &arr[i]);

    int a=0, b=n-1;
    for(int i=0; i<n; i++)
    {
        if(i and i%80 == 0) printf("\n");
        int s=a, e=b;
        while(s<e and arr[s] == arr[e])
            s++, e--;
        if(arr[s] < arr[e])
            printf("%c", arr[a++]);
        else
            printf("%c", arr[b--]);
    }  
}

/*
    
*/