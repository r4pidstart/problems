// https://www.acmicpc.net/problem/12970
// 2023-09-13 01:02:27 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    string s(n, 'B');

    int cnt=0, a_cnt=0;
    for(int i=0; i<n; i++)
    {
        if(cnt < k)
        {
            int delta=(n-i-1)-a_cnt;
            if(cnt+delta > k) 
                continue;
            else
                cnt+=(n-i-1)-(a_cnt), a_cnt++, s[i]='A';
        }
        else if(cnt==k)
            return !printf("%s", s.c_str());
    }
    printf("%d", -1);
}

/*

*/