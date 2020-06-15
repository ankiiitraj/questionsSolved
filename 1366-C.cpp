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

int n, m;

int minu(int a, int b) 
{ return (a < b)? a: b; } 
  

int mini(int a, int b, int c) 
{ return minu(minu(a, b), c);} 
  

int maxi(int a, int b) 
{ return (a > b)? a: b; } 
  

vector<vector<int>> diagonalOrder(vector<vector<int>> matrix) 
{ 
    int ROW = n, COL = m;
	vector<vector<int>> ans;
    for (int line=1; line<=(ROW + COL -1); line++) 
    { 
		vi temp;
        int start_col =  maxi(0, line-ROW); 
  
         int count = mini(line, (COL-start_col), ROW); 
  
        for (int j=0; j<count; j++) 
    		temp.push_back(matrix[minu(ROW, line)-j-1][start_col+j]);
    	ans.push_back(temp);
    } 
    return ans;
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
		int ans = 0;
		cin >> n >> m;

		vector<vi> a, dig;
		vi temp(m);

		for(int i = 1; i <= n; ++i){
			for(int j = 0; j < m ; ++j){
				cin >> temp[j];
			}
			a.push_back(temp);
		}
		
		dig = diagonalOrder(a);


		for(int i = 0, j = dig.size() -1; i < dig.size()/2; ++i, --j){
			int cnt = 0;
			for(auto itr: dig[i]){
				if(itr == 1){
					cnt++;
				}
			}
			for(auto itr: dig[j]){
				if(itr == 1){
					cnt++;
				}
			}

			if(cnt > dig[i].size()){
				ans += 2*dig[i].size() - cnt;
			}else{
				ans += cnt;
			}
		}

		cout << ans << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	