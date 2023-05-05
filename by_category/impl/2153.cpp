// https://www.acmicpc.net/problem/2153
// 2023-05-05 23:29:54
#include"bits/stdc++.h"
using namespace std;

int isprime(int a)
{
    for(long i=2; i*i<=a; i++)
        if(a%i==0) return false;
    return true;
}

int main(void)
{
#ifdef LOCAL
#endif
    string s; cin >> s;
    int sum=0;
    for(char c : s)
    {
        if(islower(c)) sum+=c-'a'+1;
        else sum+=c-'A'+26+1;
    }
    printf(isprime(sum) ? "It is a prime word." : "It is not a prime word.");
}

/*
    
*/