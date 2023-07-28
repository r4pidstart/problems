// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s; cin >> s;
    if(s=="fdsajkl;" or s=="jkl;fdsa") return !printf("in-out");
    else if(s=="asdf;lkj" or s==";lkjasdf") return !printf("out-in");
    else if(s==	"asdfjkl;") return !printf("stairs");
    else if(s==	";lkjfdsa") return !printf("reverse");
    else return !printf("molu");
}

/*
    
*/