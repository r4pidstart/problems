// https://www.acmicpc.net/problem/1049
// 2021-12-14 00:34:14 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<int> six(m), one(m);
    for(int i=0; i<m; i++) scanf("%d%d", &six[i], &one[i]);
    sort(six.begin(), six.end());
    sort(one.begin(), one.end());

    if(one[0]*6 <= six[0]) return !printf("%d", one[0]*n);

    int remain=0, sixcnt=0;
    sixcnt=n/6;
    remain=n%6;
    printf("%d", min(remain*one[0], six[0])+sixcnt*six[0]);
}

/*
    
*/