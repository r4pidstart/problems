// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class lazy_seg_tree
{
    private:
        T initial=0;
        T base=0;
        inline T f(const T& a, const T& b) 
        {
            return (a+b);
        }
        vector<int> dp;
        inline int pSum(int a, int b)
        {
            // return a+a+1+ ... +b-1+b
            return dp[b]-dp[a-1];
        }
        int size;
        vector<T> tree;
        vector<queue<int> > start;
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
        T _update(int l, int r, T v, int now, int s, int e, int st)
        {
            if(s>r or e<l) return tree[now];
            else if(l<=s and e<=r) 
            {
                start[now].push(st);
                return tree[now]=f(tree[now], pSum(st, st+(e-s)));
            }
            _lazy_update(now, s, e);
            if(l<=((s+e)/2)) // 앞부분에 포함된다면 l=10 r=100 / s=0, e=30, m=15 / 0~15 and 16~30 -> 6개 포함.
                return tree[now]=f(_update(l, r, v, now*2, s, (s+e)/2, st), _update(l, r, v, now*2+1, (s+e)/2+1, e, st+((s+e)/2)-l+1));
            else // 앞부분에 포함되지 않는다면 그대로 전달
                return tree[now]=f(_update(l, r, v, now*2, s, (s+e)/2, st), _update(l, r, v, now*2+1, ((s+e)/2)+1, e, st));
        }
        void _lazy_update(int now, int s, int e)
        {
            int m=(s+e)/2;
            while(!start[now].empty())
            {
                // st ~ st+(e-s)
                int st=start[now].front(); start[now].pop();
                if(now*2+1 < tree.size())
                {
                    start[now*2].push(st), start[now*2+1].push(st+(m-s));
                    tree[now*2]=f(tree[now*2], pSum(st, st+(m-s)));
                    tree[now*2+1]=f(tree[now*2+1], pSum(st+(m-s)+1, st+(e-s)));
                }
            }
        }
    public:
        lazy_seg_tree(int size)
        {
            this->size=size;
            tree.assign(size*4, initial);
            start.assign(size*4, queue<int>());
            dp.assign(size+1, 0);
            for(int i=1; i<=size; i++)
                dp[i]=dp[i-1]+i;
        }
        T init(const vector<T>& arr, int now=0, int s=0, int e=0)
            { return now ? _init(arr, now, s, e):_init(arr, 1, 0, size-1); }
        T get(int l, int r, int now=0, int s=0, int e=0)
            { return now ? _get(l, r, now, s, e):_get(l, r, 1, 0, size-1); }
        T update(int l, int r, T value, int now=0, int s=0, int e=0)
            { return now ? _update(l, r, value, now, s, e, value):_update(l, r, value, 1, 0, size-1, value); }
};

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    lazy_seg_tree<int> seg(n+1);
    seg.init(arr);
    int q; scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int cmd; scanf("%d", &cmd);
        switch (cmd)
        {
        case 1:
            int a,b; scanf("%d%d", &a,&b);
            seg.update(a, b, 1);
            break;
        
        default:
            int c; scanf("%d", &c);
            printf("%d\n", seg.get(c, c));
            break;
        }
    }
}

/*
    10
    1 2 3 4 5 6 7 8 9 10
    6
    1 1 5
    1 2 6
    1 5 10
    1 5 10
    1 1 8
    2 9

    ans 19
*/