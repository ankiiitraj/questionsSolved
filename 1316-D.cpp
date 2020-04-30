// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
//                                   Author : Ankit Raj								      //
//                          Problem Name    :    Nash Matrix                              //
//         	Problem Link : https://codeforces.com/contest/1316/problem/D                  //
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

struct point
{
	int x, y;
	inline bool operator == (point const &p1) {
		return (x == p1.x and y == p1.y);
	}
};

vector<point> v[5001];
char ans[5001][5001];
int n;

void dfs(point p){
	point temp;
	int i = p.x, j = p.y;
	if(i -1 >= 0 and v[i -1][j] == v[i][j] and ans[i -1][j] == 'Z'){
		ans[i -1][j] = 'D';
		temp.x = i -1, temp.y = j, dfs(temp);
	}
	if(j -1 >= 0 and v[i][j -1] == v[i][j] and ans[i][j -1] == 'Z'){
		ans[i][j -1] = 'R'; 
		temp.x = i, temp.y = j -1, dfs(temp);
	}
	if(i +1 <= n -1 and v[i +1][j] == v[i][j] and ans[i +1][j] == 'Z'){
		ans[i +1][j] = 'U';
		temp.x = i +1, temp.y = j, dfs(temp);
	}
	if(j +1 <= n -1 and v[i][j +1] == v[i][j] and ans[i][j +1] == 'Z'){
		ans[i][j +1] = 'L'; 
		temp.x = i, temp.y = j +1, dfs(temp);
	}
	return;
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
		int x, y;
		cin >> n;
		set <int> blocked;


		for(int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				ans[i][j] = 'Z';
				cin >> x >> y;
				--x, --y;
				v[i].push_back({x, y});
				if(x == i and y == j)
					ans[i][j] = 'X', blocked.insert(j + i*n);
			}
		}

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				point temp = {v[i][j].x, v[i][j].y};
				if(v[i][j].x != -2 and blocked.find(v[i][j].y + v[i][j].x*n) == blocked.end()){
					cout << "INVALID\n";
					return 0;
				}
			}
		}

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if(v[i][j].x == -2){
					if(i -1 >= 0 and v[i -1][j] == v[i][j]){
						ans[i][j] = 'U';
					}else if(j -1 >= 0 and v[i][j -1] == v[i][j]){
						ans[i][j] = 'L';
					}else if(i +1 <= n -1 and v[i +1][j] == v[i][j]){
						ans[i][j] = 'D';
					}else if(j +1 <= n -1 and v[i][j +1] == v[i][j]){
						ans[i][j] = 'R';
					}else{
						cout << "INVALID\n";
						return 0;
					}
				}
			}
		}
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if(ans[i][j] == 'X'){
					point p = {i, j};
					dfs(p);
				}
			}
		}

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if(ans[i][j] == 'Z'){
					cout << "INVALID\n";
					return 0;
				}
			}
		}
		cout << "VALID\n";
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				cout << ans[i][j];
			}
			cout << endl;
		}

	}
}