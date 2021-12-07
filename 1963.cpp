// https://www.acmicpc.net/problem/1963
// 2021-12-08 00:43:43 0ms
#include<bits/stdc++.h>
using namespace std;

vector<int> prime_table(10000, 1);

inline vector<int> int_to_digit(int n)
{
    return {n/1000, n/100%10, n/10%10, n%10};
}

inline int digit_to_int(vector<int>& v)
{
    return v[0]*1000+v[1]*100+v[2]*10+v[3];
}

int bfs(int from, int to)
{
    vector<int> visited(10000,0);
    queue<pair<int,int> > q;
    q.push({0, from});

    while(!q.empty())
    {
        auto [c, n]=q.front(); q.pop();
        if(n==to) return c;
        if(visited[n]) continue;
        visited[n]=1;

        vector<int> digit=int_to_digit(n);
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<10; j++)
            {
                digit[i]=(digit[i]+1)%10;
                int next=digit_to_int(digit);
                if(next > 999 and prime_table[next] and !visited[next])
                    q.push({c+1, next});
            }   
        }
    }

    return -1;
}

int main(void)
{
    prime_table[1]=0;
    for(int i=2; i<=100; i++)
        for(int j=i+i; j<10000; j+=i)
            prime_table[j]=0;

	int t; scanf("%d", &t);
    while(t--)
    {
        int from, to; scanf("%d%d", &from, &to);
        int ans=bfs(from, to);
        if(ans==-1) printf("Impossible\n");
        else printf("%d\n", ans);
    }
}

/*
	
*/