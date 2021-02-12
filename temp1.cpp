#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define si set<int>
#define pii pair <int, int>
#define sii set<pii>
#define vii vector<pii>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
using namespace chrono;
/*
    ----------------------------------------------------------------------
    Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

void solve(){
    int n, q, l, r;
    cin >> n >> q;
    vi a(n);
    scnarr(a, n);
    int SIZE = log2(n) +1;
    vector<vi> st(SIZE, vi(n +1, -1));

    for(int i = 0; i < n; ++i) st[0][i] = a[i];

    for(int i = 1; i < SIZE; ++i){
        for(int j = 0; j + (1 << i) <= n; ++j){
            st[i][j] = min(st[i -1][j], st[i -1][j + (1 << (i -1))]);
        }
    }

    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < n; ++j){
            cout << st[i][j] << " ";
        }
        cout << endl;
    }

    auto findMin = [&](int l, int r){
        int maxPowOf2 = log2(r - l +1);
        return min(st[maxPowOf2][l], st[maxPowOf2][r - (1 << maxPowOf2) +1]);
    };

    while(q--){
        cin >> l >> r;
        cout << findMin(l, r) << endl;
    }

    return;
}

signed main()
{
    faster;
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int t; cin >> t; while(t--)
        solve();
    return 0;
}


//Author : Ankit Raj
//Problem Link :

/*Snippets*/
/*
sieve - prime factorization using sieve and primes in range
zpower - pow with mod
plate - Initial template
bfs 
dfs
fenwik - BIT
binary_search
segment_tree
*/
