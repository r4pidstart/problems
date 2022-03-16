// https://www.acmicpc.net/problem/2003
// 2022-03-16 23:43:27 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    int cur1=0, cur2=0, tmp=0, cnt=0;
    while(cur1 < n and cur2 <= n)
    {
        if(cur2==n and tmp < m)
            break;
        
        if(tmp < m)
            tmp+=arr[cur2++];
        else if(tmp == m)
            cnt++, tmp-=arr[cur1++];
        else
            tmp-=arr[cur1++];
    }
    printf("%d", cnt);
}

/*
    
*/