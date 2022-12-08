// https://www.acmicpc.net/problem/26075
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    string a,b; cin >> a >> b;

    int cur1=0, cur2=0, cnt=0;
    
    if(n<m)
    {
        for(int i=0; i<a.length(); i++)
            a[i]=(a[i]-'0')^1 + '0', b[i]=(b[i]-'0')^1 + '0';
        swap(n,m);
    }
    
    long sum=0;
    while(cnt < m)
    {
        while(a[cur1] != '1') cur1++;
        while(b[cur2] != '1') cur2++;

        sum+=abs(cur2-cur1);
        a[cur1]='0', b[cur2]='0';
        cnt++;
    }

    printf("%ld", (sum/2)*(sum/2) + (sum-(sum/2))*(sum-(sum/2)));
}

/*
    
*/