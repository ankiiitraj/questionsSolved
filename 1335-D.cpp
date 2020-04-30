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
		string s[9];
		for(int i = 0; i < 9; ++i)
			cin >> s[i];
		if(s[0][0] != '2')
			s[0][0] = '2';
		else
			s[0][0] = '3';

		if(s[1][3] != '2')
			s[1][3] = '2';
		else
			s[1][3] = '3';

		if(s[2][6] != '2')
			s[2][6] = '2';
		else
			s[2][6] = '3';
		
		if(s[3][1] != '2')
			s[3][1] = '2';
		else
			s[3][1] = '3';
		
		if(s[4][4] != '2')
			s[4][4] = '2';
		else
			s[4][4] = '3';
		
		if(s[5][7] != '2')
			s[5][7] = '2';
		else
			s[5][7] = '3';

		if(s[6][2] != '2')
			s[6][2] = '2';
		else
			s[6][2] = '3';
		
		if(s[7][5] != '2')
			s[7][5] = '2';
		else
			s[7][5] = '3';
		
		if(s[8][8] != '2')
			s[8][8] = '2';
		else
			s[8][8] = '3';
		

		for(int i = 0; i < 9; ++i){
			cout << s[i] << endl;
		}
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	