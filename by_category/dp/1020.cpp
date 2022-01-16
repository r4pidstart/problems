// https://www.acmicpc.net/problem/1020
// 2022-01-17 04:02:52 0ms
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int flag;
vector<int> stick{6,2,5,5,4,5,6,3,7,5};
string ans;
void solve1(int n, int check, int target, int stick_cnt, string& now, string& num)
{
    if(n==now.length())
    {
        if(stick_cnt==target)
            ans=now, flag=1;
        return;
    }
    
    for(int i=0; i<10; i++)
    {
        if(flag) return;
        stick_cnt+=stick[i];
        if((target < stick_cnt + (2*(now.length()-n-1))) or target > stick_cnt + (7*(now.length()-n-1))) // 가망 없을 때
        {
            stick_cnt-=stick[i];
            continue;
        }
        now[n]=i+'0';

        if(!check) // num보다 큰 수라는 것이 확인되지 않았을 때
        {
            if(now[n]==num[n] and now!=num)
                solve1(n+1, 0, target, stick_cnt, now, num);
            else if(now[n]>num[n])
                solve1(n+1, 1, target, stick_cnt, now, num);
        }
        else
            solve1(n+1, 1, target, stick_cnt, now, num);
        
        now[n]='a';
        stick_cnt-=stick[i];
    }
}

void solve2(int n, int target, int stick_cnt, string& now)
{
    if(n==now.length())
    {
        if(stick_cnt==target)
            ans=now, flag=1;
        return;
    }
    
    for(int i=0; i<10; i++)
    {
        if(flag) return;
        stick_cnt+=stick[i];
        if((target < stick_cnt + (2*(now.length()-n-1))) or target > stick_cnt + (7*(now.length()-n-1))) // 가망 없을 때
        {
            stick_cnt-=stick[i];
            continue;
        }
        now[n]=i+'0';

        solve2(n+1, target, stick_cnt, now);
        
        now[n]='a';
        stick_cnt-=stick[i];
    }
}

int main(void)
{
    string s; cin >> s;
    int target_stick_cnt=0;
    for(int i=0; i<s.length(); i++)
        target_stick_cnt+=stick[s[i]-'0'];

    flag=0;
    string tmp(s.length(), 'a');
    
    // 1. 10^n -1에 도달하지 않고 가능한 경우
    // -> s보다 크면서, 가장 작은, 조건을 만족하는 수
    // -> ans - s
    solve1(0, 0, target_stick_cnt, 0, tmp, s);
    if(ans!="")
    {
        cout << stoll(ans)-stoll(s);
        return 0;
    }
    
    // 2. 10^n -1에 도달해야 하는 경우
    // -> 그냥 가장 작은, 조건을 만족하는 수   
    // -> 10^n -1 - s + ans + 1
    solve2(0, target_stick_cnt, 0, tmp);
    cout << (long long)(pow(10, s.length()) - 1 - stoll(s) + stoll(ans) + 1);
    assert(tmp!=ans);
}

/*
    
*/