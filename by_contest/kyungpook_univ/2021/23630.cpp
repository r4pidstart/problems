// https://www.acmicpc.net/problem/23630
// 2021-11-25 14:48:12 192ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> bits(22,0);
    for(int i=0; i<n; i++)
    {
        int tmp; scanf("%d", &tmp);
        bitset<22> b=tmp;
        for(int i=0; i<22; i++) bits[i]+=b[i];
    }
    printf("%d", *max_element(bits.begin(), bits.end()));
}

/*
    
*/