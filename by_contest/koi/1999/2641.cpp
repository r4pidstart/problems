// https://www.acmicpc.net/problem/2641
// 2022-03-27 15:03:24 0ms 
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    getchar();
    string input; getline(cin, input);
    input=input + ' ' + input;

    vector<string> ans;
    scanf("%d", &n);
    getchar();
    while(n--)
    {
        string tmp; getline(cin, tmp);
        string tmp2=tmp;
        for(auto& c : tmp2)
            if(c != ' ')
                c = (c-'0'-1 + 2) % 4 + '0' + 1;
        reverse(tmp2.begin(), tmp2.end());
        
        if(input.find(tmp)!=string::npos or input.find(tmp2)!=string::npos)
            ans.push_back(tmp);
    }
    printf("%d\n", ans.size());
    for(auto s : ans)
        cout << s << '\n';
}

/*
    
*/