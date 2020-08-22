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

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

class DNA{
	vi genes;
	int 
};

class population{
	vii 
}



int fintness(vi &a, vi &b, vii )





signed main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	srand(time(0));
	int n, t;
	cin >> n >> t;
	vector<int> a(n), b(n), res_a, res_b;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	int cnt = 0, res = 1000000000000000000;
	while(cnt < 100){
		random_shuffle(a.begin(), a.end());
		random_shuffle(b.begin(), b.end());
		int cur = 0;
		for(int i = 0; i < n; ++i){
			cur += a[i]*b[i];
		}

		if(abs(t - cur) < res){
			res = abs(t - cur);
			res_a = a;
			res_b = b;
		}
		cnt++;
	}
	cout << res << endl;
	for(auto itr: res_a){
		cout << itr << " ";
	}
	cout << endl;
	for(auto itr: res_b){
		cout << itr << " ";
	}
	cout << endl;

	return 0;
}