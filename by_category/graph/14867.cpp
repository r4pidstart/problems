// https://www.acmicpc.net/problem/14867
// 2023-10-31 20:17:10
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);

    int _gcd=gcd(a,b);

    if((c%_gcd==0 and d%b==0) or (d%_gcd==0 and c%a==0))
    {
        map<pair<int,int>, int> visited;
        queue<tuple<int, int, int> > q;

        visited[{0, 0}]=1;
        q.push({0, 0, 0});
        while(q.size())
        {
            auto [na, nb, cnt]=q.front();
            q.pop();

            if(na==c and nb==d)
                return !printf("%d", cnt);

            if(visited[{a, nb}]==0)
                q.emplace(a, nb, cnt+1), visited[{a, nb}]=1;

            if(visited[{na, b}]==0)
                q.emplace(na, b, cnt+1), visited[{na, b}]=1;

            if(visited[{0, nb}]==0)
                q.emplace(0, nb, cnt+1), visited[{0, nb}]=1;
            
            if(visited[{na, 0}]==0)
                q.emplace(na, 0, cnt+1), visited[{na, 0}]=1;
            
            int next_a, next_b;
            {
                // a to b 
                if(nb+na > b)
                    next_a=na-(b-nb), next_b=b;
                else
                    next_a=0, next_b=na+nb;

                if(visited[{next_a, next_b}]==0)
                    q.emplace(next_a, next_b, cnt+1), visited[{next_a, next_b}]=1;
            }
        
            {
                // b to a
                if(na+nb > a)
                    next_a=a, next_b=nb-(a-na);
                else
                    next_a=na+nb, next_b=0;
                    
                if(visited[{next_a, next_b}]==0)
                    q.emplace(next_a, next_b, cnt+1), visited[{next_a, next_b}]=1;
            }
        }
    }
    else
        printf("-1");
}

/*
    
*/