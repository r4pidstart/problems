// https://www.acmicpc.net/problem/1461
// 2021-12-02 02:20:19 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<int> loca(n);
    for(int i=0; i<n; i++) scanf("%d", &loca[i]);
    sort(loca.begin(), loca.end());

    // 0 전후로 나눠서, 가장 먼 곳은 한 번만
    vector<int> minus, plus;
    for(int& i : loca)
        if(i>0) plus.push_back(i);
        else minus.push_back(i);

    int sum=0;
    if(minus.size() and plus.size()) sum-=max(-minus[0], plus.back());
    else if(minus.size()) sum+=minus[0];
    else sum-=plus.back();
    
    for(int i=0; i<minus.size();)
    {
        sum+=2*-minus[i];
        i+=m;
    }
    for(int i=plus.size()-1; i>=0;)
    {
        sum+=2*plus[i];
        i-=m;
    }
    printf("%d", sum);
}

/*
    
*/