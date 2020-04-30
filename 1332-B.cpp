#include <bits/stdc++.h>
#define int long long int
#define len length
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
const int N = 1005; // 1e6 +5

/* -------------------------------Solution Sarted--------------------------------------*/

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int color[1005] = {0};
	for(int i = 2, k = 1; i*i <= 1005; ++i, ++k){
		if(color[i] == 0){
			for(int j = i; j <= 1005; j += i){
				color[j] = k;
			}
		}
	}

	int t; cin >> t; while(t--)
	{
		int n, a, k = 1;
		cin >> n;
		vi ans;
		mii s;
		for(int i = 0; i < n; ++i){
			cin >> a;
			if(s.find(color[a]) != s.end()){
				ans.push_back(s[color[a]]);
			}else{
				ans.push_back(k);
				s[color[a]] = k++;
			}
		}
		if(n <= 11){
			cout << n << endl;
			for(int i = 0; i < n; ++i){
				cout << i +1 << " ";
			}
			cout << endl;
		}else{
			cout << s.size() << endl;
			for(auto itr:ans)
				cout << itr << " ";
			cout << endl;
		}
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
