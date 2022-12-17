// https://www.acmicpc.net/problem/26264
// 2022-12-18 00:24:13      
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s; cin >> s >> s;
    int a=count(s.begin(), s.end(), 'g'), b=count(s.begin(), s.end(), 'y');
    printf("%s", a==b ? "bigdata? security!" : (a>b ? "bigdata?":"security!"));

}

/*
    
*/