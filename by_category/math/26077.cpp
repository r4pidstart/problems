// https://www.acmicpc.net/problem/26077
// 
#include"bits/stdc++.h"
using namespace std;

class Dsu
{
    public:
        vector<int> parent;
        vector<int> siz;
    public:
        Dsu(int size)
        {
            parent.assign(size, -1);
            siz.assign(size, 0);
        }
        int find(int i)
        {
            if(parent[i]<0) return i;
            else return parent[i]=find(parent[i]);
        }
        int merge(int a, int b)
        {
            a=find(a), b=find(b);
            if(a==b) return 1;

            if(parent[a]>parent[b]) swap(a,b);
            siz[a]+=siz[b];
            parent[b]=a;
            return 0;
        }
};

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n);
    Dsu dsu(1'000'001);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        dsu.siz[arr[i]]++;
    }
    
    vector<int> prime_table(1'000'001, 1);
    prime_table[0]=prime_table[1]=0;
    for(int i=2; i*i<=1'000'000; i++)
        for(int j=i+i; j<=1'000'000; j+=i)
            prime_table[j]=0;

    vector<int> prime;
    for(int i=1; i<=1'000'000; i++)
        if(prime_table[i]) prime.push_back(i);
    
    for(auto i : arr)
    {
        if(prime_table[i])
            continue;

        int tmp=i;
        for(int j=0; j<prime.size(); j++)
        {
            if(tmp % prime[j] == 0)
            {
                dsu.merge(i, prime[j]);
                while(tmp % prime[j] == 0)
                    tmp/=prime[j];
            }
            if(prime[j] * prime[j] > i)
            {
                if(tmp != 1)
                    dsu.merge(i, tmp);
                break;
            }
        }
    }

    printf("%d", *max_element(dsu.siz.begin(), dsu.siz.end()));
}

/*
    
*/