// https://www.acmicpc.net/problem/19939
// 2021-09-26 00:39:43 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);

    int reserved=(k)*(k+1)/2;
    int used=(n-reserved)/k;
    int remain=n-reserved - used*k;
    
    if(reserved > n) printf("-1");
    else printf("%d", remain==0 ? k-1:k);
}

/*
    
*/