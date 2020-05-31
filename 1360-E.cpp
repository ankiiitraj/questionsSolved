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
		int n, flag = 0;
		cin >> n;
		string s[n];
		for(int i = 0; i < n; ++i){
			cin >> s[i];
		}

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(s[i][j] == '1' and i != n -1 and j != n -1){
					if(s[i +1][j] == '1'){
						;
					}else if(s[i][j +1] == '1'){
						;
					}else{
						flag = 1;
						break;
					}
				}
			}
			if(flag)
				break;
		}

		flag ? puts("NO") : puts("YES");
		// for(int i = 0; i < n; ++i){
		// 	for(int j = 0; j < n; ++j){
		// 		cout << s[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }		

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	