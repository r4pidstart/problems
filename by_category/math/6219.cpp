// https://www.acmicpc.net/problem/6219
// 2022-07-06 23:58:30 64ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int a,b,d; scanf("%d%d%d", &a, &b, &d);
    vector<int> prime_table(b+1, 1);
    prime_table[0]=prime_table[1]=0;
    for(int i=1; i<b+1; i++)
        if(prime_table[i])
            for(int j=i+i; j<b+1; j+=i)
                prime_table[j]=0;
    
    int cnt=0;
    for(int i=a; i<=b; i++)
        if(prime_table[i] and to_string(i).find(to_string(d)) != string::npos)
            cnt++;
    printf("%d", cnt);
}

/*
    
*/