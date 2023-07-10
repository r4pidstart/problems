// https://www.acmicpc.net/problem/2346
// 2023-07-11 03:45:08
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> used(n), num(n);
    for(int i=0; i<n; i++)
        scanf("%d", &num[i]);
    
    int cur=0;
    for(int i=1; i<n; i++)
    {
        printf("%d ", cur+1);
        used[cur]=1;
        int dif=num[cur]<0 ? -1:1;
        int n_cur=cur;
        while(num[cur])
        {
            n_cur=(n_cur+dif+n)%n;
            if(!used[n_cur]) num[cur]-=dif; 
        }
        cur=n_cur;
    }
    printf("%d", cur+1);
}

/*
    
*/