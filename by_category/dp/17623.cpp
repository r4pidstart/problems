// https://www.acmicpc.net/problem/17623
// 2024-01-23 02:06:30
#include"bits/stdc++.h"
using namespace std;

bool comp(const string& a, const string& b)
{
    if(a=="") return false;
    else if(b=="") return true;

    if(a.size() != b.size()) return a.size() < b.size();
    else return a<b;
}

string min(const string& a, const string& b)
{
    return comp(a,b) ? a:b;
}

// 123456
// (){}[]

// (1) {2} [3]
// (2x) {3x} {5x}

string dp(int n)
{
    static vector<string> memo(1001, "");
    if(n==1) return "12";
    else if(n==2) return "34";
    else if(n==3) return "56";
    if(memo[n] != "") return memo[n];

    string ret="";
    if(n>2)
    {
        // plus 1
        ret=min(ret, "12"+dp(n-1));
        ret=min(ret, dp(n-1)+"12");
    }
    if(n>3)
    {
        // plus 2
        ret=min(ret, "34"+dp(n-2));
        ret=min(ret, dp(n-2)+"34");
    }
    if(n>4)
    {
        // plus 3
        ret=min(ret, "56"+dp(n-3));
        ret=min(ret, dp(n-3)+"56");
    }

    if(n%2==0)
    {
        // multiply 2
        ret=min(ret, "1"+dp(n/2)+"2");
    }
    if(n%3==0)
    {
        // multiply 3
        ret=min(ret, "3"+dp(n/3)+"4");
    }
    if(n%5==0)
    {
        // multiply 4
        ret=min(ret, "5"+dp(n/5)+"6");
    }

    for(int i=3; i<n-3; i++)
    {
        ret=min(ret, dp(n-i)+dp(i));
        ret=min(ret, dp(i)+dp(n-i));
    }

    assert(ret != "");
    return memo[n]=ret;
}

int print_str(const string& s)
{
    for(char c : s)
        printf("%c", "(){}[]"[c-'1']);
    printf("\n");       
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        print_str(dp(n));
    }
}

/*
    
*/