#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5
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
/* -------------------------------Solution Sarted--------------------------------------*/
int again = 1000000000;
int n = 0, s = 0, e = 0, w = 0;

void solve(string str, int pos, int prod, stack <int> &stk){
	if(str[pos] == 'N'){
		n =(n + prod) % again;
		solve(str, pos +1, prod, stk);
	}else if(str[pos] == 'S'){
		s =(s + prod) % again;
		solve(str, pos +1, prod, stk);
	}else if(str[pos] == 'E'){
		e =(e + prod) % again;
		solve(str, pos +1, prod, stk);
	}else if(str[pos] == 'W'){
		w =(w + prod) % again;
		solve(str, pos +1, prod, stk);
	}else if(str[pos] >= '0' and str[pos] <= '9'){
		stk.push(prod);
		int cur = str[pos] - '0';
		solve(str, pos +1, prod*cur%again, stk);
	}else if(str[pos] == ')'){
		int curProd = stk.top();
		stk.pop();
		solve(str, pos +1, curProd, stk);
	}else if(str[pos] == '('){
		solve(str, pos +1, prod, stk);
	}
}


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; for(int test = 1; test <= t; ++test)
	{
		string str;
		cin >> str;

		n = 0, s = 0, e = 0, w = 0;
		
		stack <int> stk;

		solve(str, 0, 1, stk);

		int wid = 1, hei = 1;

		if(w > e){
			wid = again - (w - e)%again +1;
		}else if(e > w){
			wid = 1 + (e - w)%again;
		}

		if(n > s){
			hei = again - (n - s)%again +1;
		}else if(s > n){
			hei = 1 + (s - n)%again;
		}

		cout << "Case #" << test << ": " << wid << " " << hei << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	