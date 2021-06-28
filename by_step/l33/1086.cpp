// https://www.acmicpc.net/problem/1086
// 2021-06-29 04:03:19 156ms
#include<bits/stdc++.h>
using namespace std;

int n,k;
string str[15];
int cache[51]={}; // 10^n 의 mod k값을 저장함
int str_cache[15]={}; // str mod k
long long dp[(1<<15)+1][101]={}; // dp[i][j] : i(mask) 상태에서 나머지가 j인 순열의 갯수 
// 모든 경우가 가능할경우 15! -> long long
int get_mod(string &str)
{
    int ret=0;
    for(int i=0, l=str.length(); i<l; i++)
    {
        ret*=10;
        ret+=str[i]-'0';
        ret%=k;
    }
    return ret;
}

long long gcd(long long a, long long b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

long long factorial(int n)
{
    if(n==1) 
        return 1;
    return n*(factorial(n-1));
}

int main(void)
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> str[i];
    cin >> k;

    cache[0]=1%k;
    for(int i=0; i<50; i++)
        cache[i+1]=(cache[i]*10)%k;

    for(int i=0; i<n; i++)
        str_cache[i]=get_mod(str[i]);

    dp[0][0]=1;
    for(int i=0, range=1<<n; i<range; i++)
        for(int j=0; j<n; j++)
            if(!(i&(1<<j))) // j번째 수열을 사용하지 않았다면
                for(int h=0; h<k; h++)
                    dp[i|(1<<j)][((h*cache[str[j].length()])%k+str_cache[j])%k]+=dp[i][h];
                    // ((직전순열*추가순열길이)+추가순열)%k = ((직전순열*추가순열길이)%k+(추가순열)%k)%k = ((직전순열%k)*(추가순열길이%k)%k+(추가순열%k))%k

    long long bot=factorial(n), top=dp[(1<<n)-1][0], factor=gcd(top, bot);
    cout << top/factor << "/" << bot/factor;
}

// (a+b)%k = ((a%k)+(b%k))%k
// (a*b)%k = (a%k)*(b%k)%k