// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
//                               Author : Ankit Raj										  //						
//                      Problem Name    :    Mike and GCD Problem                         //
//         		Problem Link : https://codeforces.com/problemset/problem/798/C            //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
#include <bits/stdc++.h>
using namespace std;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
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
 
#define int long long
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
const int N = 100005;

vector<int> a(N);

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int n, ans = 0, gcd = 0;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i], gcd = __gcd(gcd, a[i]);
	if(gcd > 1){
		cout << "YES\n0\n";
		return 0;
	}
	int temp = a[n -1];
	for(int i = 0; i < n -1; i += 2)
	{
		if(a[i]&1 and a[i +1]&1)
			ans++, a[i] = a[i +1] = 2;
		else if(!(a[i]&1))
			--i;
		else{
			ans += 2;
			a[i] = a[i +1] = 2;
		}
	}
	if(a[n -1]&1)
		ans += 2;
	cout << "YES\n" << ans << endl;
}