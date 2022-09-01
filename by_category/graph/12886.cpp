// https://www.acmicpc.net/problem/12886
// 2022-09-02 03:48:08 1696ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int a,b,c; scanf("%d%d%d", &a, &b, &c);

    const int sum=a+b+c;
    queue<pair<int,int> > q;
    q.push({a,b});
    map<pair<int,int>, int> m;
    m[{a,b}]=1;
    while(q.size())
    {
        auto now=q.front(); q.pop();
        
        int a=now.first, b=now.second, c=sum-a-b;
        if(a==b and sum-2*a==a)
            return !printf("1");
        
        if(a<b and !m[{a+a, b-a}])
            q.push({a+a, b-a}), m[{a+a, b-a}]++;
        else if(a>b and !m[{a-b, b+b}])
            q.push({a-b, b+b}), m[{a-b, b+b}]++;
        
        if(a<c and !m[{a+a, b}])
            q.push({a+a, b}), m[{a+a, b}]++;
        else if(a>c and !m[{a-c, b}])
            q.push({a-c, b}), m[{a-c, b}]++;
        
        if(b<c and !m[{a, b+b}])
            q.push({a, b+b}), m[{a, b+b}]++;
        else if(b>c and !m[{a, b-c}])
            q.push({a, b-c}), m[{a, b-c}]++;
    }
    printf("0");
}

/*
    
*/