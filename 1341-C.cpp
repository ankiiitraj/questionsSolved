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
		vi a(n);
		scnarr(a, n);
		mii m;
		set <int> pos;
		for(int i = 0; i < n; ++i){
			m[a[i]] = i +1;
			if(flag = 1)
				pos.insert(i +1);
			if(a[i] == 1 and i +1 != n){
				flag = 1;
			}
		}
		flag = 0;
		for(int i = 2; i < n; ++i){
			if(pos.empty()){
				pos.insert(m[i] +1);
			}else{
				if(m[i] != *pos.begin()){
					flag = 1;
					break;
				}
				pos.erase(*pos.begin());
			}
		}

		flag ? puts("No") : puts("Yes");
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	