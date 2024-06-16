// https://www.acmicpc.net/problem/20302
// 2024-05-27 03:58:18
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif  
    vector<int> prime_table(100001, 1);
    prime_table[0]=prime_table[1]=0;
    for(int i=2; i<=100000; i++)
        if(prime_table[i])
            for(int j=2*i; j<=100000; j+=i)
                prime_table[j]=0;

    vector<int> primes;
    for(int i=0; i<100001; i++)
        if(prime_table[i])
            primes.push_back(i);

    int n; cin >> n;
    vector<int> arr(100001);

    for(int i=0; i<n; i++)
    {
        char c; long a;
        if(i)
        {
            cin >> c >> a;
            a=abs(a);
        }
        else
        {
            cin >> a;
            a=abs(a);
            c='*';
        }
        
        int d=(c=='*') ? 1:-1;

        for(int p : primes)
        {
            if(p*p > a)
                break;
            while(!(a%p))
                arr[p]+=d, a/=p;
        }
        arr[a]+=d;
    }

    if(arr[0])
        return cout << "mint chocolate", 0;
    
    for(int i=2; i<100001; i++)
        if(arr[i]<0)
            return cout << "toothpaste", 0;
    cout << "mint chocolate";
}

/*

*/