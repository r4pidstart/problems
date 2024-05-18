// https://www.acmicpc.net/problem/11443
// 2024-05-09 19:24:23
#include"bits/stdc++.h"
using namespace std;

template <class T>
class matrix
{
public:
    vector<vector<T> > mat;
    long mod;
    matrix(int a, int b, long mod=LONG_MAX, int init=0)
    {
        this->mod=mod;
        mat=vector<vector<T> >(a, vector<T>(b, init));
    }
    inline size_t size(void) const
    {
        return mat.size();
    }
    vector<T>& operator[](size_t a)
    {
        return this->mat[a];
    }
    const vector<T>& operator[](size_t a) const
    {
        return this->mat[a];
    }
    matrix<T> operator*(const matrix& b) const
    {
        const matrix& a=*this;
        matrix<T> ret(a.size(), b[0].size(), mod);

        if(a[0].size() != b.size() or a.mod != b.mod)
            throw runtime_error("rte on matrix multiplication");
        for(int i=0; i<a.size(); i++)
            for(int j=0; j<b[0].size(); j++)
            {
                for(int k=0; k<b.size(); k++)
                    ret[i][j]=(1L*ret[i][j]+a[i][k]*b[k][j])%mod;
            }
        return ret;
    }
    static matrix<T> pow(const matrix& a, size_t n)
    {
        if(n==1) return a;
        matrix<T> tmp=matrix<T>::pow(a, n/2);
        tmp=tmp*tmp;
        if(n&1) tmp=tmp*a;
        return tmp;
    }
    int print(void)
    {
#ifdef LOCAL
        for(int i=0; i<this->size(); i++)
        {
            for(int j=0; j<this->mat[0].size(); j++)
                cout << this->mat[i][j] << ' ';
            printf("\n");
        }
#endif
        return 0;
    }
};

int main(void)
{
    long n; scanf("%ld", &n);
    matrix<long> mat(3, 3, 1e9+7);
    mat[0][0]=2;
    mat[0][1]=1;
    mat[1][0]=1;
    mat[1][1]=1;
    mat[2][1]=1;
    mat[2][2]=1;

    matrix<long> ans(3, 1, 1e9+7);
    ans[0][0]=1; // f1
    ans[1][0]=0; // f0
    ans[2][0]=0; // even sum

    printf("%ld", (matrix<long>::pow(mat, n/2+1)*ans)[2][0]);
}

/*
    내가 원하는 것
    -> 한 번 돌리면 f(n+2), f(n+1)이 만들어지는 행렬

    f(n) -> f(n+2)
    f(n-1) -> f(n+1)

    f(n)+f(n+1) = f(n+2)
    2*f(n)+f(n-1) = f(n+2)

    [2 1 0] [ f(n) ]   [f(n+2)]
    [1 1 0] [f(n-1)] = [f(n+1)]
    [0 1 1] [ esum ]   [f(n) + esum]
*/