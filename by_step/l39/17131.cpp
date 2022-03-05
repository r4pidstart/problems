// https://www.acmicpc.net/problem/17131
// 2022-03-06 04:36:13 228ms
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class seg_tree
{
    private:
        T initial=0;
        T base=0;
        inline T f(const T& a, const T& b) 
        {
            return (a+b);
        }
        int size;
        vector<T> tree;
        T _init(const vector<T>& arr, int now, int s, int e)
        {
            if(s==e) return tree[now]=arr[s];
            else return tree[now]=f(_init(arr, now*2, s, (s+e)/2), _init(arr, now*2+1, ((s+e)/2)+1, e)); 
        }
        T _get(int l, int r, int now, int s, int e)
        {
            if(s>r or e<l) return base;
            else if(l<=s and e<=r) return tree[now];
            else return f(_get(l, r, now*2, s, (s+e)/2), _get(l, r, now*2+1, ((s+e)/2)+1, e));
        }
        T _update(int i, T v, int now, int s, int e)
        {
            if(!(s<=i and i<=e)) return tree[now];
            else if(s==e and s==i) return tree[now]=tree[now]+v;
            else return tree[now]=f(_update(i, v, now*2, s, (s+e)/2), _update(i, v, now*2+1, ((s+e)/2)+1, e));
        }
    public:
        seg_tree(int size)
        {
            this->size=size;
            tree.assign(size*4, initial);
        }
        T init(const vector<T>& arr, int now=0, int s=0, int e=0)
            { return now ? _init(arr, now, s, e):_init(arr, 1, 0, size-1); }
        T get(int l, int r, int now=0, int s=0, int e=0)
            { return now ? _get(l, r, now, s, e):_get(l, r, 1, 0, size-1); }
        T update(int index, T value, int now=0, int s=0, int e=0)
            { return now ? _update(index, value, now, s, e):_update(index, value, 1, 0, size-1); }
};

int main(void)
{
    int n; scanf("%d", &n);
    struct _star {int x, y, idx;};
    vector<_star> star(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &star[i].x, &star[i].y);
    
    vector<pair<int, int> > range(400001, {INT32_MAX, INT32_MIN}); // -2*1e5 ~ 2*1e5
    seg_tree<int> stars_seg(n);

    sort(star.begin(), star.end(), [](const _star& a, const _star& b)->bool { return a.x < b.x; });
    for(int i=0; i<n; i++)
    {
        range[star[i].x+2e5].first = min(range[star[i].x+2e5].first, i); // left 
        range[star[i].x+2e5].second = max(range[star[i].x+2e5].second, i); // right
        stars_seg.update(i, 1);
        star[i].idx=i;
    }

    long long ans=0;
    sort(star.begin(), star.end(), [](const _star& a, const _star& b)->bool { return a.y < b.y; });
    int cur=0;
    for(int i=-2e5; i<=2e5; i++)
    {
        int start=cur;
        while(cur<n and star[cur].y == i)
            stars_seg.update(star[cur].idx, -1), cur++; // 같은 높이를 빼주기
        
        for(;start<cur; start++)
        {
            int left=range[star[start].x+2e5].first, right=range[star[start].x+2e5].second;
            // 0 ~ left -1, right +1 ~ n-1
            if(left == 0 or right == n-1) continue; // 어느 한 쪽에 더 이상 별이 없는 경우.
            int left_stars=stars_seg.get(0, left-1);
            int right_stars=stars_seg.get(right+1, n-1);
            ans=(ans+((long long)left_stars * right_stars))%(int)(1e9+7);
        }
    }
    printf("%lld", ans);
}

/*
    일단, 좌우 위치를 기준으로 세그먼트 트리에 모든 별을 넣는다. 

    별들을 높이 기준으로 정렬한 뒤, 낮은 별부터 살펴보자.
    같은 높이의 별들을 x좌표 기준으로 세그먼트 트리에서 제거한다.
    그렇다면, 해당 별의 좌,우에 더 높이 있는 별들의 갯수를 각각 구할 수 있고, 둘을 곱해주면 해당 별을 중심으로 만들 수 있는 모든 별자리의 갯수를 구할 수 있다.
*/