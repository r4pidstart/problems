// https://www.acmicpc.net/problem/2840
// 2023-11-04 00:42:52
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    vector<char> arr(n, -1);
    int idx=0;
    while(k--)
    {
        int a; char c; scanf("%d %c", &a, &c);
        idx=(idx+a)%n;
        if(arr[idx] == -1)
            arr[idx]=c;
        else if(arr[idx] != c)
            return !printf("!");
    }

    vector<int> used(26, 0);
    for(int i=0; i<n; i++)
        if(arr[i]!=-1 and used[arr[i]-'A']++)
            return !printf("!");

    for(int i=0; i<n; i++)
    {
        if(arr[(idx-i+n)%n] == -1)
            printf("?");
        else 
            printf("%c", arr[(idx-i+n)%n]);
    }
}

/*
    
*/