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
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
	int t; cin >> t; while(t--)
	{
		int n, k, c, temp;
		cin >> n >> k;
		set<int> s[k];

		for(int i = 0; i < k; ++i){
			cin >> c;
			for(int j = 0; j < c; ++j){
				cin >> temp;
				s[i].insert(temp);
			}
		}

		int which, _max, _newMax;

		cout << "? " << n << " ";
		for(int i = 0; i < n; ++i){
			cout << i +1 << " ";
		} 
		cout << endl;
		cin >> _max;

		int l = 1, r = n, mid;
		while(l < r){
			mid = (l + r)/2;

			cout << "? " << (mid - l +1) << " ";
			for(int i = l; i <= mid; ++i){
				cout << i << " ";
			}
			cout << endl;
			cin >> _newMax;
			if(_newMax == _max){
				r = mid;
			}else{
				l = mid +1;
			}
		}

		for(int i = 0; i < k; ++i){
			if(s[i].find(l) != s[i].end()){
				cout << "? " << n - s[i].size() << " ";
				for(int j = 0; j < n; ++j){
					if(s[i].find(j +1) == s[i].end()){
						cout << j +1 << " ";
					}
				}
				cout << endl;
				cin >> _newMax;
				break;
			}
		}
		cout << "! ";
		for(int i = 0; i < k; ++i){
			if(s[i].find(l) != s[i].end()){
				cout << _newMax << " ";
			}else{
				cout << _max << " ";
			}
		}
		cout << endl;
		string str;
		cin >> str;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	