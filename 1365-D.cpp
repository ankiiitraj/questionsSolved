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

bool visited[51][51];
string s[51];
int n, m;

void dfs(int i, int j){
	visited[i][j] = 1; 

	if(s[i][j] == '#' or s[i][j] == '*'){
		return;
	}

	if(i < n -1 and !visited[i +1][j]){
		if(s[i +1][j] == 'B'){
			if(s[i][j] == 'G'){
				s[i][j] = '*';
			}else{
				s[i][j] = '#';
			}
			return;
		}
		dfs(i +1, j);
	}
	if(i > 0 and !visited[i -1][j]){
		if(s[i -1][j] == 'B'){
			if(s[i][j] == 'G'){
				s[i][j] = '*';
			}else{
				s[i][j] = '#';
			}
			return;
		}
		dfs(i -1, j);
	}
	if(j < m -1 and !visited[i][j +1]){
		if(s[i][j +1] == 'B'){
			if(s[i][j] == 'G'){
				s[i][j] = '*';
			}else{
				s[i][j] = '#';
			}
			return;
		}
		dfs(i, j +1);
	}
	if(j > 0 and !visited[i][j -1]){
		if(s[i][j -1] == 'B'){
			if(s[i][j] == 'G'){
				s[i][j] = '*';
			}else{
				s[i][j] = '#';
			}
			return;
		}
		dfs(i, j -1);
	}
}

int cntG;
void Dfs(int i, int j){
	visited[i][j] = 1; 

	if(s[i][j] == '*'){
		return;
	}
	if(s[i][j] == '#')
		return;
	if(s[i][j] == 'G'){
		cntG++;
	}
	bool ans = 0;
	if(i < n -1 and !visited[i +1][j]){
		Dfs(i +1, j);
	}
	if(i > 0 and !visited[i -1][j]){
		Dfs(i -1, j);
	}
	if(j < m -1 and !visited[i][j +1]){
		Dfs(i, j +1);
	}
	if(j > 0 and !visited[i][j -1]){
		Dfs(i, j -1);
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
	int t; cin >> t; while(t--)
	{
		memset(visited, 0, sizeof(visited));
		cin >> n >> m;
		for(int i = 0; i < n; ++i)
			cin >> s[i];

		int cnt = 0;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j)
				if(s[i][j] == 'G')
					cnt++;
				// cout << s[i][j] << " ";
			// cout << endl;
		}
		dfs(n -1, m -1);
		
		cntG = 0;
		memset(visited, 0, sizeof(visited));
		Dfs(n -1, m -1);
		
		if(cntG != cnt){
			puts("NO");
		}else{
			puts("YES");
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	