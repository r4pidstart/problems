// https://www.acmicpc.net/problem/15918
// 2024-07-07 21:57:28
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int solution(int now, int n, int x, int y)
{
    static vector<int> used(n+1);
    static vector<int> arr(2*n);
    
    if(arr[x]!=arr[y])
        return 0;
    if(now==2*n)
        return 1;
    if(arr[now])
        return solution(now+1, n, x, y);

    int ret=0;
    for(int i=1; i<=n; i++)
    { 
        if(now+i+1>=2*n) 
            break;
        if(arr[now+i+1] or used[i])
            continue;

        used[i]=1;
        arr[now]=arr[now+i+1]=i;
        ret+=solution(now+1, n, x, y);
        arr[now]=arr[now+i+1]=0;
        used[i]=0;    
    }
    return ret;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,x,y; cin >> n >> x >> y;
    cout << solution(0, n, x-1, y-1);
}

/*
    
*/
