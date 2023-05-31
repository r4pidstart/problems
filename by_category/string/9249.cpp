// https://www.acmicpc.net/problem/9249 
// 2023-06-01 00:49:56
#include"bits/stdc++.h"
using namespace std;

vector<int> sa, pos;
int d;

int comp(int a, int b)
{
    if(pos[a] != pos[b]) 
        return pos[a]<pos[b];
    a+=d, b+=d;
    if(a<sa.size() and b<sa.size()) return pos[a]<pos[b];
    else return a>b;
}

void get_sa(string& s)
{
    int n=s.length();
    sa.assign(n, 0), pos.assign(n, 0);

    for(int i=0; i<n; i++)
        pos[i]=s[i], sa[i]=i;
    for(d=1; ; d*=2)
    {
        sort(sa.begin(), sa.end(), comp);
        
        vector<int> tmp(n);
        for(int i=1; i<n; i++)  
            tmp[i]=tmp[i-1]+comp(sa[i-1], sa[i]);
        for(int i=0; i<n; i++)
            pos[sa[i]]=tmp[i];

        if(tmp.back()==n-1) break;
    }
}

vector<int> get_lcp(string& s)
{
    int n=s.length();
    vector<int> lcp(n);
    get_sa(s);

    for(int i=0, k=0; i<n; i++, k=max(0, k-1))
    {
        if(!pos[i]) continue;

        int j=sa[pos[i]-1];
        while(s[i+k] == s[j+k]) k++;
        lcp[pos[i]]=k;
    }
    return lcp;
}

int main(void)
{
#ifdef LOCAL
#endif
    string a,b; cin >> a >> b;
    string s=a+' '+b;

    auto lcp=get_lcp(s);

    int ans_l=0, ans_s=-1;
    for(int i=1; i<s.length(); i++)
    {
        // 두 일치하는 부분이 각각 다른 문자열에 속해야댐ㅁ
        if(((sa[i]<a.length() and a.length()<sa[i-1]) or (sa[i]>a.length() and sa[i-1]<a.length())) and lcp[i] > ans_l) 
            ans_l=lcp[i], ans_s=sa[i];
    }
    printf("%d\n%s", ans_l, s.substr(ans_s, ans_l).c_str());
}

/*
    
*/