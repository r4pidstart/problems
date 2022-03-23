// https://www.acmicpc.net/problem/5532
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int l,a,b,c,d; scanf("%d%d%d%d%d", &l, &a, &b, &c, &d);
    printf("%d", l - (int)ceil(max((double)b/d, (double)a/c)));
}

/*
    
*/