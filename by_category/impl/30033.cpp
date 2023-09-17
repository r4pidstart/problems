// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        if(a>=arr[i]) cnt++;
    }
    printf("%d", cnt);
}

/*
    
*/