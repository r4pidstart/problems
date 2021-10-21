// https://www.acmicpc.net/problem/1645
// 2021-10-22 01:23:18 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n+1,0);
    // n명일때 오겠다는 사람 수
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        arr[a]++;
    }

    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        cnt+=arr[i];
        if(cnt > i) 
        {
            printf("%d", cnt);
            return 0;
        }
    }
    printf("%d", cnt);
}

/*
    
*/