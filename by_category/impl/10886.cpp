// https://www.acmicpc.net/problem/10886
// 2022-03-17 21:18:42 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        if(a) cnt++;
    }
    printf("%s", cnt>n/2 ? "Junhee is cute!":"Junhee is not cute!");
}

/*
    
*/