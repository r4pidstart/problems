// https://www.acmicpc.net/problem/6784
// 2023-11-04 00:47:43
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<char> arr(n);
    for(int i=0; i<n; i++)
        scanf(" %c", &arr[i]);
    
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        char a; scanf(" %c", &a);
        if(arr[i]==a) cnt++;
    }
    printf("%d", cnt);
}

/*
    
*/