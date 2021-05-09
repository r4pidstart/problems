// https://www.acmicpc.net/problem/4195
// 2021-05-09 23:05:50 312ms
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
// 양수이면 부모의 위치, 음수이면 해당 트리의 깊이
map<string, int> str_i;

int find(int a)
{
    if(parent[a]>=0)
    {
        int tmp=a;
        while(parent[a]>=0)
            a=parent[a];
        parent[tmp]=a;
    }
    return a;
}

int size(int a)
{
    return -parent[find(a)];
}

void merge(int a, int b)
{
    a=find(a), b=find(b);
    if(a==b)
        return;
    if(parent[a]<parent[b]) // a가 b보다 깊다면
    {
        parent[a]+=parent[b];
        parent[b]=a;
    }
    else
    {
        parent[b]+=parent[a];
        parent[a]=b;
    }
}

int main(void)
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        str_i.clear(), parent.assign(200000,-1);
        int n; 
        cin >> n;
        for(int i=0; i<n; i++)
        {
            string a,b;
            cin >> a >> b;

            if(str_i.find(a)==str_i.end())
                str_i[a]=str_i.size();
            if(str_i.find(b)==str_i.end())
                str_i[b]=str_i.size();

            merge(str_i[a],str_i[b]);
            cout << size(str_i[a]) << "\n";
        }
    }
}