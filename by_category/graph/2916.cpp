// https://www.acmicpc.net/problem/2916
// 2024-01-03 01:27:10
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    vector<int> dp(360);
    queue<int> q;
    q.push(0);

    while(q.size())
    {
        int now=q.front();
        q.pop();

        for(auto i : arr)
        {
            if(!dp[(now+i)%360])
                dp[(now+i)%360]=1, q.push((now+i)%360);
            if(!dp[(now-i+360)%360])
                dp[(now-i+360)%360]=1, q.push((now-i+360)%360);
        }
    }
    for(int i=0; i<k; i++)
    {
        int a; scanf("%d", &a);
        printf("%s\n", dp[a] ? "YES":"NO");
    }
}

/*
    
*/