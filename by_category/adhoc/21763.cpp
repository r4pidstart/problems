// https://www.acmicpc.net/problem/21763
// 2023-06-02 03:14:48
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    if(n==2 and k>=2 or k>n*n-n) return !printf("NO");
    vector<vector<char> > arr(n, vector<char>(n, '.'));

    printf("YES");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i!=j and k) arr[i][j]='#', k--;
    
    if(n>1)
        swap(arr[1], arr[n-2]);

    printf("\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%c", arr[i][j]);
        printf("\n");
    }
}

/*
    if n is odd
    o....
    .o...
    ..o..
    ...o.
    ....o

    if n is even
    -> just swap 2nd and n-2th line.
    o...
    ..o.
    .o..
    ...o

    o.
    .o <- edge case
*/