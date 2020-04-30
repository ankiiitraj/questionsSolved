#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


int n;
vector <string> l;
string st, en;
int memo[100000];
// set <string> used;

int solve(int idx, int prev){
    // used.insert(cur);
    cout << idx << " " << prev << endl;
    if(l[idx] == en){
        return 0;
    }
    if(memo[idx] != -1)
        return memo[idx];

    int ans = INT_MAX;
    for(int i = 1; i <= n +1; ++i){
        if(l[i] != l[idx] and l[i] != l[prev]){
            int j = 0, cnt = 0;
            for( ; j < l[idx].length(); ++j){
                if(l[i][j] != l[idx][j]){
                    cnt++;
                }
                if(cnt > 1)
                    break;
            }
            if(j == l[idx].length()){
                ans = min(ans, solve(i, idx) +1);
            }
        }
    }
    cout << endl;
    memo[idx] = ans;
    return ans;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    memset(memo, -1, sizeof(memo));
    cin >> st >> en >> n;
    l.resize(n +2);
    l[0] = st;
    for(int i = 1; i <= n; ++i){
        cin >> l[i];
    }    
    debug(l);
    // sort(l.begin(), l.end());
    l[n +1] = en;
    cout << solve(1, 0) << endl;

}