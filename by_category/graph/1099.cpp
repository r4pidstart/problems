// https://www.acmicpc.net/problem/1099
// 2022-09-15 01:33:42
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    string s; cin >> s;
    int n; scanf("%d", &n);
    vector<string> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    queue<pair<int, int> > q;
    q.push({0, 0});

    vector<int> visited(s.length()+1, INT32_MAX);
    while(q.size())
    {
        int pos=q.front().first, val=q.front().second;
        q.pop();

        if (pos == s.size())
            continue;
            
        for(auto i : arr)
        {
            int tmp=0;
            if(s.size() - pos >= i.size())
            {
                vector<int> cnt1(26), cnt2(26);
                for(int j=0; j<i.size(); j++)
                {
                    if(s[pos+j] != i[j]) tmp++;
                    cnt1[s[pos+j]-'a']++, cnt2[i[j]-'a']++;
                }
                if(cnt1 == cnt2 and visited[pos+i.size()] > val+tmp)
                    q.push({pos+i.size(), val+tmp}), visited[pos+i.size()]=val+tmp;
            }
        }
    }
    printf("%d", visited[s.size()] == INT32_MAX ? -1:visited[s.size()]);
}

/*
    
*/