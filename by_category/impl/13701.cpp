// https://www.acmicpc.net/problem/13701
// 2022-08-02 02:25:09 1332ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int a;
    int masking[(1<<20)+1]={};
    while(scanf("%d", &a) != EOF)
    {
        int target_idx=a/32;
        if(!(masking[target_idx] & (1<<(a%32))))
            printf("%d ", a);
        masking[target_idx]|=(1<<(a%32));
    }
}

/*
    
*/