// https://www.acmicpc.net/problem/2754
// 2022-03-29 00:55:03 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    if(s=="A+") printf("4.3");
    else if(s=="A0") printf("4.0");
    else if(s=="A-") printf("3.7");
    else if(s=="B+") printf("3.3");
    else if(s=="B0") printf("3.0");
    else if(s=="B-") printf("2.7");
    else if(s=="C+") printf("2.3");
    else if(s=="C0") printf("2.0");
    else if(s=="C-") printf("1.7");
    else if(s=="D+") printf("1.3");
    else if(s=="D0") printf("1.0");
    else if(s=="D-") printf("0.7");
    else if(s=="F") printf("0.0");
}

/*
    
*/