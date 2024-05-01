// https://www.acmicpc.net/problem/31784
// 2024-04-29 19:40:06
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    string s; cin >> s;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        arr[i]=s[i]-'A';

    for(int i=0; i<n; i++)
    {
        // a 만들 수 있나?
        if(arr[i] and k >= 26-arr[i])
            k-=26-arr[i], arr[i]=0;

        // 마지막거?
        if(i==n-1)
            arr[i]=(arr[i]+k)%26;
    }

    for(int i=0; i<n; i++)
        printf("%c", arr[i]+'A');
}

/*
    
*/