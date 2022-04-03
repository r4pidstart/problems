// https://www.acmicpc.net/problem/17410
// 2022-04-04 00:54:47 548ms
#pragma GCC optimize ("O3,Ofast,unroll-loops")
#pragma GCC target("avx2")
#include<immintrin.h>
#include<bits/stdc++.h>
using namespace std;

alignas(32) int16_t arr[101000], res[16];

int main(void)
{
    cin.tie(NULL)->sync_with_stdio(false);
    
    int n; cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int q; cin >> q;
    while(q--)
    {
        int c; cin >> c;
        if(c==1)
        {
            int i,v; cin >> i >> v;
            arr[i-1]=v;
        }
        else
        {
            int s,e,k; cin >> s >> e >> k;
            s--, e--;

            int cnt1 = 0;
            while(s & 15 and s <= e)
                cnt1+=(arr[s++] > k);
            
            while(e+1 & 15 and s <= e)
                cnt1+=(arr[e--] > k);

            __m256i cnt2 = _mm256_set1_epi16(0);
            __m256i comp1 = _mm256_set1_epi16(k);
            __m256i comp2 = _mm256_set1_epi16(1);
            __m256i *s_ptr = (__m256i *)&arr[s];
            __m256i *e_ptr = (__m256i *)&arr[e+1];

            while(s_ptr != e_ptr)
            {
                __m256i tmp = _mm256_cmpgt_epi16(*s_ptr, comp1);
                tmp = _mm256_and_si256(tmp, comp2);
                cnt2 = _mm256_add_epi16(tmp, cnt2);
                s_ptr++;
            }
            _mm256_store_si256((__m256i *)res, cnt2);
            for(int i=0; i<16; i++)
                cnt1+=res[i];
            cout << cnt1 << '\n';
        }
    }    
}

/*
    
*/