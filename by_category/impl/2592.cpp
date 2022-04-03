// https://www.acmicpc.net/problem/2592
// 2022-04-03 16:27:19 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n=10;
    map<int,int> m;
    int sum=0;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        m[a]++;
        sum+=a;
        if(m[a] > m[ans]) ans=a;
    }
    printf("%d\n%d", sum/10, ans);
}

/*
    
*/