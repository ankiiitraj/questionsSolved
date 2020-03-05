// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
//                               Author : Ankit Raj										  //
//                      Problem Name    :    Mike and Distribution                        //
//         		Problem Link : https://codeforces.com/problemset/problem/798/D            //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define debug cout << "Debugging . . .\n";
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
const int N = 100005;

vector<int> ai(N), bi(N), Temp;

struct point {
	int x, y, id;
};

bool cmp(point &a, point &b){
	if(a.x == b.x){
		return a.y > b.y;
	}
	return a.x > b.x;
}
bool Cmp(point &a, point &b){
	if(a.y == b.y){
		return a.x > b.x;
	}
	return a.y > b.y;
}

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while (t--)
	{
		int n, temp, sumA = 0, sumB = 0;
		cin >> n;

		vector <point> a(n), t1, t2;
		set <int> ans;

		for (int i = 0; i < n; ++i)
			cin >> a[i].x, sumA += a[i].x;
		for (int i = 0; i < n; ++i)
			cin >> a[i].y, a[i].id = i + 1, sumB += a[i].y;
		cout << n/2 +1 << endl;
		while(1){
			shuffle(a.begin(), a.end(), default_random_engine(0));
			int cntA = 0, cntB = 0;
			for(int i = 0; i < n/2 +1; ++i){
				cntA += a[i].x;
				cntB += a[i].y;
			}
			if(2*cntA > sumA and 2*cntB > sumB){
				for(int i = 0; i < n/2 +1; ++i){
					cout << a[i].id << " ";
				}
				break;
			}
		}	
	}
}