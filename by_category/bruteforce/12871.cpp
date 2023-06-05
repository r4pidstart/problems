// https://www.acmicpc.net/problem/12871
// 2023-06-06 02:26:28
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s1, s2;
    cin >> s1 >> s2;
    if(s1.size() > s2.size())
        swap(s1, s2);

    stringstream ss1, ss2;
    for(int i=0; i<50; i++)
    {
        ss2 << s2;
        ss1=stringstream();
        for(int j=0; j<50; j++)
        {
            ss1 << s1;
            if(ss1.str() == ss2.str()) return !printf("1");
        }
    }
    printf("0");
}

/*
    
*/