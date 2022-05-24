// https://www.acmicpc.net/problem/8983
// 2022-05-25 03:35:59 80ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int m,n,l; scanf("%d%d%d", &m, &n, &l);
    vector<int> shooter(m);
    for(int i=0; i<m; i++)
        scanf("%d", &shooter[i]);    
    sort(shooter.begin(), shooter.end());

    int cnt=0;
    for(int i=0; i<n; i++)
    {
        int x,y; scanf("%d%d", &x, &y);
        auto it=lower_bound(shooter.begin(), shooter.end(), x);
        if(it != shooter.end() and l >= abs(*it-x)+y) cnt++;
        else if(it != shooter.begin() and l >= abs(*(it-1)-x)+y) cnt++;
    }
    printf("%d", cnt);
}

/*
    
*/