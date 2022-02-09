// https://www.acmicpc.net/problem/5525
// 2022-02-09 23:45:44 40ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k; scanf("%d %d", &n, &k);
    string s; cin >> s;
    int cnt=0, prev, ans=0;
    for(int i=0; i<k; i++)
    {
        if(!cnt and s[i] == 'I') cnt++, prev='I';
        else if(cnt and prev != s[i]) cnt++, prev=s[i];
        else if(s[i] == 'I') cnt=1, prev='I';
        else cnt=0;
        if(s[i] == 'I' and cnt > 2*n) ans++;
    }
    printf("%d", ans);
}

/*
    
*/