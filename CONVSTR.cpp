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

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int n, flag = 0;
		string a, b;
		cin >> n >> a >> b;

		for(int i = 0; i < n; ++i){
			if(b[i] > a[i]){
				flag = 1;
				break;
			}
		}
		if(flag){
			cout << -1 << endl;
			continue;
		}

		vector <set<int>> ans;
		int steps = 0;
		{

			for(int i = 25; i >= 0; --i){
				set<int> temp;
				for(int j = 0; j < n; ++j){
					if(a[j] == i + 'a'){
						temp.insert(j);
						break;
					}
				}
				if(temp.size() == 0){
					flag = 1;
				}
				int cnt = 0;
				for(int j = 0; j < n; ++j){
					if(b[j] == (char)('a' + i)){
						if(a[j] != b[j])
							cnt++;
						a[j] = b[j];
						temp.insert(j);
					}
				}
				debug(a);
				if(flag and temp.size() > 0){
					break;
				}else{
					flag = 0;
				}
				if(cnt != 0){
					ans.push_back(temp);
					++steps;
				}
			}

			// // for(int i = 0; i < n; ++i){
			// // 	if(a[i] != b[i]){
			// // 		for(int j = 0; j < n; ++j){
			// // 			if(a[j] == b[i]){
			// // 				temp.insert(j);
			// // 				break;
			// // 			}
			// // 		}
			// // 		if(temp.size() == 0){
			// // 			flag = 1;
			// // 			break;
			// // 		}
			// // 		for(int j = 0; j < n; ++j){
			// // 			if(b[j] == b[i]){
			// // 				temp.insert(j);
			// // 				a[j] = b[i];	
			// // 			}
			// // 		}
		
			// // 		// debug(a, i);
			// // 		if(temp.size() <= 1){
			// // 			flag = 1;
			// // 			break;
			// // 		}
			// 	}
			// }
			
			if(a != b or flag){
				cout << -1 << endl;
				continue;
			}
			cout << steps << endl;
			for(auto itr: ans){
				cout << itr.size() << " ";
				for(auto it: itr){
					cout << it << " ";
				}
				cout << endl;
			}
		}

		// debug("--");
		

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	
