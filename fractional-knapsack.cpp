#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
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
    Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

void solve(){
    int n, W;
    cin >> n >> W;
    vi v(n), w(n);
    vector<pair<double, pair<int, int>>> ratios;
    for(int i = 0; i < n; ++i){
        cin >> v[i] >> w[i];
        ratios.push_back({(double)((v[i]*1.00)/(w[i]*1.00)), {v[i], w[i]}});
    }
    sort(all(ratios));
    double ans = 0.00;
    for(int itr = n -1; itr >= 0; --itr){
        if(ratios[itr].second.second*1.00 <= W){
            ans += ratios[itr].second.first*1.00;
            W -= ratios[itr].second.second*1.00;
        }else{
            ans += (W)*(ratios[itr].first)*1.00;
            break;
        }
    }
    cout << ans << endl;
    
}

signed main()
{
    faster;
// #ifndef ONLINE_JUDGE
//     freopen("ip.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
// #endif
    cout << fixed << setprecision(2);
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
    