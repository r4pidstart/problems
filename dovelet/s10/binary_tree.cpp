// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        int ca=0, cb=0;
        while(a!=1 && b!=1)
        {
            if(a>b) ca+=(a/b), a%=b;
            else cb+=(b/a), b%=a; 
        }
        if(a>1) ca+=a-1;
        else cb+=b-1;
        printf("Scenario #%d:\n%d %d\n\n", i, ca, cb);
    }
}

/*
    
*/