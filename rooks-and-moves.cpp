#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<int>> dph(n, vector<int>(m, 0));
    vector<vector<int>> dpv(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
            dph[i][j] = dpv[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i][j] == '#'){
                continue;
            }
            dph[i][j] = j == 0 ? 1 : dph[i][j -1] +1;
        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(a[j][i] == '#'){
                continue;
            }
            dpv[j][i] = j == 0 ? 1 : dpv[j -1][i] +1;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = m -2; j >= 0; --j){
            if(a[i][j] == '#'){
                continue;
            }
            dph[i][j] = max(dph[i][j +1], dph[i][j]);

        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = n -2; j >= 0; --j){
            if(a[j][i] == '#'){
                continue;
            }
            dpv[j][i] = max(dpv[j +1][i], dpv[j][i]);
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            ans = max(ans, dph[i][j] + dpv[i][j] -1);
        }
    }
    cout << ans << endl;
    
    return 0;
}
