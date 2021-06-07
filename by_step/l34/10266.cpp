// https://www.acmicpc.net/problem/10266
// 2021-06-01 23:20:21 92ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    // 오름차순 정렬 (nlogn) -> 요소간의 차 구하기 (n) -> a문자열 2개 이어붙이고 kmp로 찾기(n)
    // 상대적인 각도가 뭐던간에, 두 집단이 동일하다는것을 확인하기만 하면 됨

    int n; scanf("%d", &n);
    vector<int> str1(n), str2(n);
    
    for(int i=0; i<n; i++)
        scanf("%d", &str1[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &str2[i]);
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    int tmp_str1_0=str1[0], tmp_str2_0=str2[0];
    for(int i=0; i<n-1; i++)
    {
        str1[i]=str1[i+1]-str1[i];
        str2[i]=str2[i+1]-str2[i];
    }
    str1[n-1]=360000 - str1[n-1] + tmp_str1_0;
    str2[n-1]=360000 - str2[n-1] + tmp_str2_0;

    // kmp
    vector<int> pi(n,0);
    int begin=1, m=0;
    while(begin + m < n)
    {
        if(str2[begin+m]==str2[m])
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

    begin=0, m=0;
    int cycle=1;
    while(begin<=n-m)
    {
        if(m<n && str1[begin+m]==str2[m])
        {
            m++;
            if(begin+m==n && cycle) // 문자열을 이어붙이는 부분
                cycle--, begin=-m;
            if(m==n)
            {
                printf("possible");
                return 0;
            }    
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
    printf("impossible");
    return 0;
}