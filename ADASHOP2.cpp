#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353; // 1e9 + 7
const int N = 1000001; // 1e6 +1

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
		int r, c;
		cin >> r >> c;
		if(r  != 1 or c != 1){
			cout << 27 << endl; 
			cout << (r + c)/2 << " " << (r + c)/2 << endl;
			cout << "1 1\n";
		}else{
			cout << 25 << endl;
		}             
		cout << "2 2\n";
		cout << "1 3\n";
		cout << "3 1\n"; 
		cout << "2 2\n";
		cout << "3 3\n";
		cout << "1 5\n";
		cout << "5 1\n"; 
		cout << "3 3\n";
		cout << "4 4\n";
		cout << "1 7\n";
		cout << "7 1\n"; 
		cout << "4 4\n";
		cout << "5 5\n";
		cout << "2 8\n";
		cout << "8 2\n"; 
		cout << "5 5\n";
		cout << "6 6\n";
		cout << "4 8\n";
		cout << "8 4\n"; 
		cout << "6 6\n";
		cout << "7 7\n";
		cout << "6 8\n";
		cout << "8 6\n"; 
		cout << "7 7\n";
		cout << "8 8\n";

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
