// https://www.acmicpc.net/problem/1323
// 2022-12-25 12:34:40
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    long tmp=0;

    int cnt=0;
    set<long> se;
    while(se.find(tmp) == se.end())
    {
        se.insert(tmp);
        tmp=stoll(to_string(tmp)+to_string(n)) % k;
        cnt++;
        if(tmp == 0)
            return !printf("%d", cnt);
    }
    printf("-1");
}

/*
    
*/