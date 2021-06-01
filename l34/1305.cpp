// https://www.acmicpc.net/problem/1305
// 2021-06-01 18:37:44 16ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    char *s=new char[n];
    scanf("%s", s);
    
    int begin=1, m=0;
    vector<int> pi(n, 0);
    while(begin+m < n)
    {
        if(s[begin+m] == s[m])
        {
            m++;
            pi[begin+m-1]=m;
        }
        else
        {
            if(m==0)
                begin++;
            else
            {
                begin+=m-pi[m-1];
                m=pi[m-1];
            }
        }
    }

    printf("%d", n-pi[n-1]);
    // pi[n-1]은 첫 패턴을 제외한 반복되는 문자열의 길이
}