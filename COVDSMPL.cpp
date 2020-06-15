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

/* -------------------------------Solution Sarted--------------------------------------*/
map <string, int> dp;
int n;
bool a[61][61];

int is_present(int i, int j, int k, int l){
	int x;
	string cur = to_string(i) + '|' + to_string(j) + '|' + to_string(k) + '|' + to_string(l);
	if(dp.find(cur) != dp.end()){
		x = dp[cur];
	}else{
		cout << "1 " << i << " " << j << " " << k << " " << l << endl;
		cin >> x;
		dp[cur] = x;
	}
	return x;
}

void update(int i, int j, int val){
	if(val == 1){
		a[i][j] = 1;
	}else{
		a[i][j] = 0;
	}
}

int32_t main()
{
	// faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
	int t; cin >> t; while(t--)
	{
		int p, x, total;
		cin >> n >> p;

		dp.clear();

		for(int i = 1; i <= n/2; ++i){
			for(int j = 1; j <= n/2; ++j){
				int whole, right, down, digonal;
				whole = is_present(i, j, n, n);
				if(i == 1 and j == 1){
					total = whole;
				}
				right = is_present(i, j +1, n, n);
				down = is_present(i +1, j, n, n);
				digonal = is_present(i +1, j +1, n, n);

				whole -= right;
				down -= digonal;
				whole -= down;

				if(whole == 1){
					a[i][j] = 1;
				}else{
					a[i][j] = 0;
				}
			}
		}

		for(int i = 1; i <= n/2; ++i){
			for(int j = n/2 +1; j <= n; ++j){
				int whole, left, down, digonal;
				whole = is_present(i, 1, n, j);
				left = is_present(i, 1, n, j -1);
				down = is_present(i +1, 1, n, j);
				digonal = is_present(i +1, 1, n, j -1);

				whole -= left;
				down -= digonal;
				whole -= down;

				if(whole == 1){
					a[i][j] = 1;
				}else{
					a[i][j] = 0;
				}
			}
		}

		for(int i = n/2 +1; i <= n; ++i){
			for(int j = 1; j <= n/2; ++j){
				int whole, right, up, digonal;
				whole = is_present(1, j, i, n);
				right = is_present(1, j +1, i, n);
				up = is_present(1, j, i -1, n);
				digonal = is_present(1, j +1, i -1, n);

				whole -= right;
				up -= digonal;
				whole -= up;

				if(whole == 1){
					a[i][j] = 1;
				}else{
					a[i][j] = 0;
				}
			}
		}
		
		for(int i = n/2 +1; i <= n; ++i){
			for(int j = n/2 +1; j <= n; ++j){
				if(i == n and j == n){
					break;
				}
				int whole, left, up, digonal;
				whole = is_present(1, 1, i, j);
				left = is_present(1, 1, i, j -1);
				up = is_present(1, 1, i -1, j);
				digonal = is_present(1, 1, i -1, j -1);

				whole -= left;
				up -= digonal;
				whole -= up;

				if(whole == 1){
					a[i][j] = 1;
				}else{
					a[i][j] = 0;
				}
			}
		}

		int counter = 0;
		cout << "2\n";
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(i == n and j == n){
					if(counter != total){
						cout << "1 ";
					}else{
						cout << "0 ";
					}
					break;
				}
				if(a[i][j]){
					cout << "1 ";
					counter++;
				}else{
					cout << "0 ";
				}
			}
			cout << endl;
		}
		cin >> x;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
