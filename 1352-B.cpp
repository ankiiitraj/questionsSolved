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

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int n, k;
		cin >> n >> k;

		if(n&1 and !(k&1)){
			cout << "NO\n";
		}else if(n&1){
			if(k -1 < n){
				cout << "YES\n";
				for(int i = 0; i < k -1; ++i){
					cout << "1 ";
				}
				cout << n - (k -1) << endl; 
			}else{
				cout << "NO\n";
			}
		}else{
			if(!(k&1) and k -1 < n){
				cout << "YES\n";
				for(int i = 0; i < k -1; ++i){
					cout << "1 ";
				}
				cout << n - (k -1) << endl; 
			}else{
				if(2*(k -1) < n){
					cout << "YES\n";
					for(int i = 0; i < k -1; ++i){
						cout << "2 ";
					}
					cout << n - 2*(k -1) << endl; 
				}else{
					cout << "NO\n";
				}
			}
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
