// https://www.acmicpc.net/problem/2138
// 2022-08-20 05:17:04 16ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    bitset<100001> original, target;
    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%1d", &tmp);
        original[i]=tmp;
    }
    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%1d", &tmp);
        target[i]=tmp;
    }
    for(int i=0; i<n; i++)
        scanf("%1d", &target[i]);

    int cnt1=0, cnt2=0;
    
    bitset<100001> tmp=original;
    cnt1++, tmp[0].flip(), tmp[1].flip();
    for(int i=1; i<n; i++)
        if(tmp[i-1] != target[i-1]) cnt1++, tmp[i-1].flip(), tmp[i].flip(), tmp[i+1].flip();
    if(tmp[n-1] != target[n-1]) cnt1=INT32_MAX;

    tmp=original;
    for(int i=1; i<n; i++)
        if(tmp[i-1] != target[i-1]) cnt2++, tmp[i-1].flip(), tmp[i].flip(), tmp[i+1].flip();
    if(tmp[n-1] != target[n-1]) cnt2=INT32_MAX;

    if(cnt1 == INT32_MAX and cnt2 == INT32_MAX)
        printf("-1");
    else
        printf("%d", min(cnt1, cnt2));
}

/*
    
*/