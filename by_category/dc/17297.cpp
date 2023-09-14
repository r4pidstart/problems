// https://www.acmicpc.net/problem/17297    
// 2023-09-15 00:07:26
#include"bits/stdc++.h"
using namespace std;

string solution(int n, vector<long>& len)
{
    if(n<string("Messi Gimossi").length())
    {
        if(n==5) return "Messi Messi Gimossi";
        else return string("Messi Gimossi").substr(n, 1);
    }
    auto it=lower_bound(len.begin(), len.end(), n);
    if(*it == n)
        return "Messi Messi Gimossi";
    return solution(n-*prev(it)-1, len);
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<long> len(1000);
    len[1]=string("Messi").length(), len[2]=len[1]+1+string("Gimossi").length();
    
    int cur=2;
    while(len[cur++] < INT32_MAX)
        len[cur]=len[cur-1]+1+len[cur-2];
    len.resize(cur);
    printf("%s", solution(n-1, len).c_str());
}

/*
    
*/