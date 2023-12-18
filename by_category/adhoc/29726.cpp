// https://www.acmicpc.net/problem/29726
// 2023-12-17 19:38:17
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    priority_queue<int, vector<int> > pq;
    int ans=arr.back() - arr.front();
    for(int i=0; i<m; i++)
    {
        pq.push(arr[n-i-1]);
        ans=max(ans, pq.top()-arr[m-i]);
    }
    
    printf("%d", ans);
}   

/*
    sigma(A_2 to A_L) - sigma(A_1 to A_L-1)

    -> A_2+A_3+A_4+A_5 - (A_1+A_2+A_3+A_4)
    -> A_5 - A_1

    max(Ax - Ay, x>y)

*/