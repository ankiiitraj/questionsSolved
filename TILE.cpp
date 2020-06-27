#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt", "r", stdin)
#define output freopen("Output.txt", "w", stdout);
#define what_is(x) cout << #x << " is " << x << endl;
#define pb push_back
#define eb emplace_back
#define inf 1000000000
#define mod 1000000007


void matmult(ll a[][2], ll b[][2], ll c[][2])
{
    int i, j, k;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < 2; k++)
            {
                c[i][j] += (a[i][k] * b[k][j]);
                c[i][j] %= mod;
            }
        }
    }
}

void matpow(ll Z[][2], ll n, ll ans[][2])
{
    ll temp[2][2];
    ans[0][0] = 0;
    ans[1][0] = 1;
    ans[0][1] = 1;
    ans[1][1] = 1;
    ll i, j;
    while (n > 0)
    {
        if (n & 1)
        {
            matmult(ans, Z, temp);
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 2; j++)
                {
                    ans[i][j] = temp[i][j];
                }
            }
        }
        matmult(Z, Z, temp);
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                Z[i][j] = temp[i][j];
            }
        }
        n /= 2;
    }
    return;
}

ll findFib(ll n)
{
    ll fib;
    if(n>2)
    {
        ll int Z[2][2] = {{0,1},{1,1}},result[2][2];
        matpow(Z,n-2,result);
        fib = result[0][0]*0+result[0][1]*1;
    }
    else 
        fib = n-1;
    return fib;
}

void solve()
{
    int T; cin>>T;
    while(T--)
    {
        ll n; cin>>n;
        ll ans = findFib(n+2);
        cout<<ans<<"\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
    solve();
    return 0;
}