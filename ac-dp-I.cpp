

//   _________   ______                    ______            ______  _________  ______
//  |           |      \      /\    /|    |     |  |        |            |     |
// |           |        \     / \  / |    |     |  |        |            |     |
// \          |          \    /  \/  |    |_____|  |        |______      |     |_____
//  \         \          /    /      |    |        |        |            |     |
//   \________ \________/     /      |    |        |______  |______      |     |______



//          ||  |||||||||||||||
//          ||        ||
//          ||        ||
//          ||        ||
//          ||        ||
//          ||        ||
//          ||        ||
//







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
int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    cout << fixed << setprecision(10);
	int n;
	cin >> n;
	vector<double> p(n +1);
	double all_head = 1.0;
	for(int i = 0; i < n; ++i){
		cin >> p[i +1];
		p[i +1] = 1.0 - p[i +1];
	}
	debug(p);
	double dp[n +2] = {0.0}, ans = 0.0;
	for(int i = n; i > 0; --i){
		dp[i] = p[i] + dp[i +1];
		ans += p[i];
	}
	cout << ans << endl;
	// for(int i = 2; i <= n/2; ++i){
	// 	for(int j = n; j >= 0; --j){
	// 		dp[j] = p[j -1]*dp[j +1] + dp[j +1];
	// 		ans += p[j -1]*dp[j +1];
	// 	}
	// }


}