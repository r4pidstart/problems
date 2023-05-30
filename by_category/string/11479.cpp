// https://www.acmicpc.net/problem/11479
// 2023-05-31 04:25:10
#include"bits/stdc++.h"
using namespace std;

int d;/*for cmp_sa*/
vector<int> pos/*group number*/, sa/*start location*/;

int cmp_sa(int a, int b)
{
    if(pos[a]!=pos[b]) return pos[a]<pos[b];
    a+=d, b+=d;
    if(a<pos.size() and b<pos.size()) return pos[a]<pos[b];
    else return a>b;
}

void get_sa(string& s)
{
    int n=s.length();
    pos.assign(n, 0), sa.assign(n, 0);
    for(int i=0; i<n; i++)
        pos[i]=s[i], sa[i]=i;
    
    d=1;
    while(true)
    {
        sort(sa.begin(), sa.end(), cmp_sa);

        vector<int> tmp(n);
        for(int i=1; i<n; i++)
            tmp[i]=tmp[i-1]+cmp_sa(sa[i-1], sa[i]);
        for(int i=0; i<n; i++)
            pos[sa[i]]=tmp[i];
        
        if(tmp.back() == n-1) break;
        d*=2;
    }
}

vector<int> get_lcp(string& s)
{
    int n=s.size();
    vector<int> lcp(n);

    for(int i=0, k=0; i<n; i++, k=max(k-1, 0))
    {
        if(pos[i]==0) continue; // first idx
        
        int j=sa[pos[i]-1];
        while(s[j+k] == s[i+k]) k++;
        lcp[pos[i]]=k;
    }
    return lcp;
}

int main(void)
{
#ifdef LOCAL
#endif
    string s; cin >> s;
    get_sa(s);
    auto lcp=get_lcp(s);

    long ans=0;
    for(int i=0; i<s.length(); i++)
        ans+=(s.length()-sa[i]-lcp[i]);
    printf("%ld", ans);
}

/*

*/