// http://220.89.64.243/30stair/zerosum/zerosum.php?pname=zerosum
//
#include<bits/stdc++.h>
using namespace std;

string str;

void calculate(void)
{
    vector<int> num(1);
    vector<char> oper;
    num[0]=str[0]-'0';

    // space
    for(int i=1; i<str.length(); i+=2)
    {
        if(str[i]==' ') num[num.size()-1]=num[num.size()-1] * 10 + str[i+1]-'0';
        else num.push_back(str[i+1]-'0'), oper.push_back(str[i]);
    }

    int sum=num[0];
    for(int i=0; i<oper.size(); i++)
    {
        if(oper[i]=='+') sum+=num[i+1];
        else sum-=num[i+1];
    }

    if(sum==0) cout << str << '\n';
}

void dfs(int s, int e, int now)
{
    if(now==e)
    {
        str+=to_string(now);
        calculate();
        str.pop_back();
    }
    else
    {
        str+=to_string(now);

        str+=' ';
        dfs(s, e, now+1);
        str.pop_back();

        str+='+';
        dfs(s, e, now+1);
        str.pop_back();

        str+='-';
        dfs(s, e, now+1);
        str.pop_back();

        str.pop_back();
    }
}

int main(void)
{
    int n; scanf("%d", &n);
    dfs(1, n, 1);
}

/*
    
*/