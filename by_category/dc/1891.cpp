// https://www.acmicpc.net/problem/1891
// 2024-01-28 02:10:58
#include"bits/stdc++.h"
using namespace std;

pair<long, long> get_xy(const string& s, int idx, long x, long y)
{
    if(s.length()==idx) return {x, y};

    if(s[idx] == '1')
        return get_xy(s, idx+1, x*2+0, y*2+1);
    else if(s[idx] == '2')
        return get_xy(s, idx+1, x*2, y*2);
    else if(s[idx] == '3')
        return get_xy(s, idx+1, x*2+1, y*2);
    else
        return get_xy(s, idx+1, x*2+1, y*2+1);
}

string get_origin(long x, long y, int idx)
{
    if(!idx and x==0 and y==0) return "";
    if(!idx) return "-";

    if(x%2==0 and y%2==0)
        return get_origin(x/2, y/2, idx-1)+'2';
    else if(x%2==0 and y%2==1)
        return get_origin(x/2, y/2, idx-1)+'1';
    else if(x%2==1 and y%2==0)
        return get_origin(x/2, y/2, idx-1)+'3';
    else
        return get_origin(x/2, y/2, idx-1)+'4';
}

int main(void)
{
#ifdef LOCAL
#endif
    int d; string s;
    cin >> d >> s;
    long dx, dy; scanf("%ld %ld", &dx, &dy);

    auto origin=get_xy(s, 0, 0, 0);
    if(origin.first-dy < 0 or origin.second+dx < 0)
        return !printf("-1");
    string ret=get_origin(origin.first-dy, origin.second+dx, d);
    #ifdef LOCAL
        printf("%s\n", ret.c_str());
    #endif
    if(ret.size() != s.size())
        return !printf("-1");
    printf("%s", ret.c_str());
}

/*
    
*/