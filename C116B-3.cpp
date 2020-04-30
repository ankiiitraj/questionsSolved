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
const int MOD = (int)1e9 +7; // 1e9 + 7
const int N = 1000005; // 1e6 +5

/* -------------------------------Solution Sarted--------------------------------------*/

int power(int x, int y){
	if(y == 0)
		return 1;
	if(y&1)
		return (x*power(x, y -1))%MOD;
	int temp = power(x, y/2)%MOD;
	return (temp*temp)%MOD;
}

vector<bool> decToBinary(int n) 
{ 
	vector <bool> res(33);
    for (int i = 33, j = 0; i >= 0; i--, ++j) { 
        int k = n >> i; 
        if (k & 1) 
        	res[j] = 1;
        else
        	res[j] = 0; 
    } 

    return res;
}

int32_t main()
{

	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int n, ans = 1;
		cin >> n;
		vi a(n);
		scnarr(a, n);
		for(int i = 1; i < n; ++i){
			vector<bool> cur, res;
			int cnt = 0, flag = 0;
			cur = decToBinary(a[i -1]);
			res = decToBinary(a[i]);
			for(int j = 0; j <= 33; ++j){
				if(res[j] == 1 and cur[j] == 1){
					cnt++;
				}else if(res[j] == 0 and cur[j] == 1){
					flag = 1;
					break;
				}
			}
			if(flag){
				ans = 0;
				break;
			}
			int curRes = power(2, cnt)%MOD;
			ans = (ans*curRes)%MOD;
		}

		cout << ans << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	