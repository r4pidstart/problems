// https://www.acmicpc.net/problem/
//
#include "bits/stdc++.h"
using namespace std;

long mypow(int n)
{
    long ret = 1;
    while (n--)
        ret *= 10;
    return ret;
}

long get_ans(long target, int idx, vector<long>& cand)
{
    if(idx==cand.size())
        return 0;
    
    if(to_string(cand[idx])[0]=='2') // bruteforce
    {
        if(target>=cand[idx])
            return min(get_ans(target, idx+1, cand), get_ans(target-cand[idx], idx+1, cand)+1);
    }
    else if(to_string(cand[idx])[0]=='5')
    {
        long tmp=target/cand[idx];
        if(tmp)
            return min(get_ans(target-(tmp-1)*cand[idx], idx+1, cand)+(tmp-1)*2, get_ans(target-tmp*cand[idx], idx+1, cand)+tmp*2);
    }

    long ret=get_ans(target-(target/cand[idx])*cand[idx], idx+1, cand);
    return ret+target/cand[idx];
}

int main(void)
{
#ifdef LOCAL
#endif
    int t;
    scanf("%d", &t);
    vector<long> cand;
    for (int i = 0; i < 16; i++)
        cand.push_back(mypow(i));
    for (int i = 0; i < 8; i++)
        cand.push_back(mypow(2 * i) * 25), cand.push_back(mypow(2 * i) * 50);
    sort(cand.begin(), cand.end(), greater<>());

    while (t--)
    {
        long n;
        scanf("%ld", &n);
        printf("%ld\n", get_ans(n, 0, cand));
    }
}

/*

*/