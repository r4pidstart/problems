// https://www.acmicpc.net/problem/19942
// 2021-09-25 04:39:58 0ms
#include<bits/stdc++.h>
using namespace std;

struct nut
{
    int n,p,f,s,v,price;
    bool operator<(nut &a) const
    {
        return price<a.price;
    }
};

int ans=INT32_MAX;
int mp,mf,ms,mv; 
int np=0,nf=0,ns=0,nv=0,price=0;
vector<int> ansv, used, v;
vector<nut> arr;

void dfs(int n, int l)
{
    if(mp<=np && mf<=nf && ms<=ns && mv<=nv)
    {
        if(price < ans)
        {
            ans=price;
            ansv=v;
        }
    }
    else if(n==l)
    {
        return;
    }
    else
    {
        v[n]=arr[n].n;
        price+=arr[n].price;
        np+=arr[n].p, nf+=arr[n].f, ns+=arr[n].s, nv+=arr[n].v;
        dfs(n+1, l);

        v[n]=0;
        price-=arr[n].price;
        np-=arr[n].p, nf-=arr[n].f, ns-=arr[n].s, nv-=arr[n].v;
        dfs(n+1, l);
    }
}

int main(void)
{
    int n; scanf("%d", &n);
    scanf("%d%d%d%d", &mp,&mf,&ms,&mv);
    int cp=0, cf=0, cs=0, cv=0;
    arr.assign(n,{});
    v.assign(n,0);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d%d%d", &arr[i].p, &arr[i].f, &arr[i].s, &arr[i].v, &arr[i].price);
        arr[i].n=i+1;
        cp+=arr[i].p, cf+=arr[i].f, cs+=arr[i].s, cv+=arr[i].v;
    }

    if(!(mp<=cp && mf<=cf && ms<=cs && mv<=cv))
    {
        printf("-1");
        return 0;
    }

    dfs(0, n);

    printf("%d\n", ans);
    sort(ansv.begin(), ansv.end());
    for(int i : ansv)
        if(i!=0)
            printf("%d ", i);
}

/*
    
*/