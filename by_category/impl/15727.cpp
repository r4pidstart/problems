// https://www.acmicpc.net/problem/15727
//2022-04-03 17:29:14 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int l; scanf("%d", &l);
    if(l%5 == 0) l--;
    printf("%d",  l / 5 + 1);
}

/*
    
*/