#include<bits/stdc++.h>
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


int main() {
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	int n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<int> a(m), mentored(n +1, 0);
    for(int i = 0; i < m; ++i){
		cin >> a[i];
    }
    
    for(int i = 0; i < m; ++i){
		for(int j = max(a[i] - k, 1); j <= min(n, a[i] + k); ++j){
			mentored[j] = 1;
        }
    }
    for(int i = 1; i <= n; ++i){
        if(!mentored[i]){
            int j = i;
			while(!mentored[j]){
                ++j;
            }
            int cnt = j - i;
            ans += (cnt%(2*k +1) == 0 ? cnt/(2*k +1) : cnt/(2*k +1) +1);
            i = j -1;
            cout << ans << " ";
        }
    }
    
    cout << ans << endl;
    
}