// https://www.acmicpc.net/problem/11900
// 2024-03-21 21:26:02
#include"bits/stdc++.h"
using namespace std;

class dijkstra
{
    // graph[from]={to, cost}, O(V^2+E)
    public:
        vector<int> dist;
        dijkstra(int start, const vector<int>& arr)
        {
            const int n=arr.size();

            vector<int> visited(n, 0);
            dist.assign(n, INT32_MAX/2);
            dist[start]=0;
            
            while(true)
            {
                int now=-1, shortest=INT32_MAX;
                for(int i=0; i<n; i++)
                    if(shortest>dist[i] and !visited[i])
                        now=i, shortest=dist[i];
                if(now==-1) break;

                visited[now]=1;
                for(int i=0; i<n; i++)
                {
                    if(now==i or visited[i]) continue;
                    int nxt_idx=(now-i+n)%n;
                    assert(nxt_idx>0);
                    dist[i]=min(
                        dist[i], 
                        arr[nxt_idx] ? dist[now]+arr[nxt_idx]:INT32_MAX/2
                    );
                }
            }
        }
};

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n-1; i++)
        scanf("%d", &arr[i+1]);
    
    dijkstra dijk(0, arr);

    int q; scanf("%d", &q);
    while(q--)
    {
        int a,b; scanf("%d%d", &a, &b);
        int ans=dijk.dist[(b-a+n)%n];
        printf("%d\n", ans==INT32_MAX/2 ? -1:ans);
    }

}

template <typename T>
class lazy_seg_tree // 1-based
{
    private:
        T initial=0;
        T base=0;
        inline T f(const T& a, const T& b) 
        {
            return (a+b);
        }
        int size;
        vector<T> tree, lazy;
        T _init(const vector<T>& arr, int now, int s, int e)
        {
            if(s==e) return tree[now]=arr[s];
            else return tree[now]=f(_init(arr, now*2, s, (s+e)/2), _init(arr, now*2+1, ((s+e)/2)+1, e));
        }
        T _get(int l, int r, int now, int s, int e)
        {
            if(s>r or e<l) return base;
            else if(l<=s and e<=r) return tree[now];
            _lazy_update(now, s, e);
            return f(_get(l, r, now*2, s, (s+e)/2), _get(l, r, now*2+1, ((s+e)/2)+1, e));
        }
        T _update(int l, int r, T v, int now, int s, int e)
        {
            if(s>r or e<l) return tree[now];
            else if(l<=s and e<=r) 
            {
                lazy[now]=f(lazy[now], v*(e-s+1));
                return tree[now]=f(tree[now], v*(e-s+1));
            }
            _lazy_update(now, s, e);
            return tree[now]=f(_update(l, r, v, now*2, s, (s+e)/2), _update(l, r, v, now*2+1, ((s+e)/2)+1, e));
        }
        void _lazy_update(int now, int s, int e)
        {
            if(lazy[now])
            {
                int m=(s+e)/2;
                tree[now*2]=f(tree[now*2], lazy[now]/(e-s+1) * (m-s+1));
                lazy[now*2]=f(lazy[now*2], lazy[now]/(e-s+1) * (m-s+1));
                tree[now*2+1]=f(tree[now*2+1], lazy[now]/(e-s+1) * (e-m));
                lazy[now*2+1]=f(lazy[now*2+1], lazy[now]/(e-s+1) * (e-m));
                lazy[now]=0;
            }
        }
    public:
        lazy_seg_tree(int size)
        {
            this->size=size;
            tree.assign(size*4, initial);
            lazy.assign(size*4, 0);
        }
        T init(const vector<T>& arr, int now=0, int s=0, int e=0)
            { return now ? _init(arr, now, s, e):_init(arr, 1, 0, size-1); }
        T get(int l, int r, int now=0, int s=0, int e=0)
            { return now ? _get(l, r, now, s, e):_get(l, r, 1, 0, size-1); }
        T update(int l, int r, T value, int now=0, int s=0, int e=0)
            { return now ? _update(l, r, value, now, s, e):_update(l, r, value, 1, 0, size-1); }
};

/*
    
*/