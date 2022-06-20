// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    for(int i=-999; i<1000; i++)
        for(int j=-999; j<1000; j++)
            if(a*i+b*j==c and d*i+e*j==f)
                return !printf("%d %d", i, j);
}

/*
    
*/