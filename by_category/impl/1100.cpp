// https://www.acmicpc.net/problem/1100
// 2022-03-14 21:13:21 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int cnt=0;
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            char c; scanf(" %c", &c);
            if((!(i&1) and !(j&1)) or ((i&1) and (j&1)))
                if(c=='F') cnt++;
        }
    printf("%d", cnt);
}

/*
    
*/