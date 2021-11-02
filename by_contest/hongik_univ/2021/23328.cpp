// https://www.acmicpc.net/problem/23328
// 2021-11-03 03:49:32 I
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; char bomb;
    scanf("%d %c ", &n,&bomb);
    vector<char> upper, lower, bombs;
    int shield_cnt=0;
    for(int i=0; i<n; i++)
    {
        char tmp; scanf("%c", &tmp);
        if(tmp==bomb) bombs.push_back(tmp);
        else if('A'<=tmp and tmp<='Z') upper.push_back(tmp);
        else if(tmp==bomb-'A'+'a') shield_cnt++, lower.push_back(tmp);
        else lower.push_back(tmp);
    }

    sort(upper.begin(), upper.end());
    sort(lower.begin(), lower.end());

    if(shield_cnt==0) // 한 개를 터트려야 하는 경우
    {
        string s1, s2;
        // 맨 앞에 폭탄
        for(char& c : bombs) s1+=c; // 폭탄 설치
        for(char& c : upper) s1+=c; // 대문자
        for(char& c : lower) s1+=c; // 소문자

        // 맨 뒤에 폭탄
        for(char& c : upper) s2+=c; // 대문자
        for(char& c : lower) s2+=c; // 소문자
        for(char& c : bombs) s2+=c; // 폭탄 설치

        cout << min(s1, s2);
    }
    else if(shield_cnt==1) // 양 끝에 폭탄이 위치한 경우
    {
        string s1, s2;
        // 맨 앞에 폭탄
        auto target=lower_bound(lower.begin(), lower.end(), bomb-'A'+'a'); // 쉴드 위치
        for(char& c : bombs) s1+=c; // 폭탄 설치
        s1+=bomb-'A'+'a'; // 쉴드 한 개
        for(char& c : upper) s1+=c; // 대문자
        for(auto it=lower.begin(); it<target; it++) s1+=*it; // 쉴드 직전까지
        for(auto it=target+1; it<lower.end(); it++) s1+=*it; // 쉴드 하나 뺀 다음부터

        // 맨 뒤에 폭탄
        for(char& c : upper) s2+=c; // 대문자
        for(auto it=lower.begin(); it<target; it++) s2+=*it; // 쉴드 직전까지
        for(auto it=target+1; it<lower.end(); it++) s2+=*it; // 쉴드 하나 뺀 다음부터
        s2+=bomb-'A'+'a'; // 쉴드 한 개
        for(char& c : bombs) s2+=c; // 폭탄 설치

        cout << min(s1, s2);
    }
    else 
    {
        string s1, s2;
        // 맨 앞에 폭탄
        auto target=lower_bound(lower.begin(), lower.end(), bomb-'A'+'a'); // 쉴드 위치
        for(char& c : bombs) s1+=c; // 폭탄 설치
        s1+=bomb-'A'+'a'; // 쉴드 한 개
        for(char& c : upper) s1+=c; // 대문자
        for(auto it=lower.begin(); it<target; it++) s1+=*it; // 쉴드 직전까지
        for(auto it=target+1; it<lower.end(); it++) s1+=*it; // 쉴드 하나 뺀 다음부터

        // 중간에 폭탄
        for(char& c : upper) s2+=c; // 대문자
        for(auto it=lower.begin(); it<target; it++) s2+=*it; // 쉴드 직전까지
        s2+=bomb-'A'+'a'; // 쉴드 한 개
        for(char& c : bombs) s2+=c; // 폭탄 설치
        for(auto it=target+1; it<lower.end(); it++) s2+=*it; // 쉴드 하나 뺀 다음부터

        cout << min(s1, s2);
    }
}

/*
    
*/