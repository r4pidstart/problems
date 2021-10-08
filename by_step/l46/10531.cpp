// https://www.acmicpc.net/problem/10531
// 2021-10-09 03:29:08 160ms
#include<bits/stdc++.h>
using namespace std;

void fft(vector <complex<double>> &a, bool invert){
    int n = a.size();
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*M_PI/len*(invert?-1:1);
        complex<double> wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            complex<double> w(1);
            for (int j=0;j<len/2;j++){
                complex<double> u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i=0;i<n;i++) a[i] /= n;
    }
}
void multiply(vector<int> &a, vector<int> &b, vector<int> &ret){
    vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)a.size()+(int)b.size()) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    ret.resize(n);
    for (int i=0;i<n;i++) ret[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> a(200001, 0); 
     for(int i=1; i<=n; i++)
    {
        int tmp; scanf("%d", &tmp);
        a[tmp]=1;
    }
    vector<int> ret, b(a.begin(), a.end());
    multiply(a,b,ret);

    int ans=0;
    int m; scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        int tmp; scanf("%d", &tmp);
        if(ret[tmp] || a[tmp]) ans++;
    }
    printf("%d", ans);
}

/*
    
*/