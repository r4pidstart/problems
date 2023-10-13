// https://www.acmicpc.net/problem/15312
// 2023-10-14 03:12:55
#include"bits/stdc++.h"
using namespace std;

string solution(string target)
{
    if(target.size()==2)
        return target;

    string tmp;
    for(int i=0; i<target.size()-1; i++)
        tmp+=to_string((target[i]+target[i+1]-2*'0')%10);

    return solution(tmp);
}

int main(void)
{
#ifdef LOCAL
#endif
    int cnt[]={3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

    string s1, s2; 
    cin >> s1 >> s2;

    string target;
    for(int i=0; i<s1.size(); i++)
        target+=to_string(cnt[s1[i]-'A']), target+=to_string(cnt[s2[i]-'A']);
    
    printf("%s", solution(target).c_str());
}

/*
    
*/