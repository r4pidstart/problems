// https://www.acmicpc.net/problem/15811
// 2023-09-23 22:10:50 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vector<int> ma(128);

    vector<char> lst;
    for(char c : s1)
        lst.push_back(c);
    for(char c : s2)
        lst.push_back(c);
    for(char c : s3)
        lst.push_back(c);

    sort(lst.begin(), lst.end());
    lst.resize(unique(lst.begin(), lst.end())-lst.begin());

    if(lst.size() > 10)
        return !printf("NO\n");

    int ans=0;
    vector<int> permu(10);
    iota(permu.begin(), permu.end(), 0);
    do
    {
        int cnt=0;
        for(char c : lst)
            ma[c]=permu[cnt++];

        long a=0, b=0, c=0;
        for(auto c : s1)
            a=a*10+ma[c];
        for(auto c : s2)
            b=b*10+ma[c];
        for(auto d : s3)
            c=c*10+ma[d];

        if(a+b==c)
            return !printf("YES");

    } while (next_permutation(permu.begin(), permu.end()));
    return !printf("NO");
}

/*
    
*/