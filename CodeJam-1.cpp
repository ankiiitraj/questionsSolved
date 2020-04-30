#include<bits/stdc++.h>
using namespace std;

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("ip.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
// #endif
    int t; cin >> t;
    for(int test = 1; test <= t; ++test){
        
        int n, nc = 0, nr = 0, ans = 0;
        cin >> n;
        int a[n][n];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> a[i][j];
                if(j == i){
                    ans += a[i][j];                    
                }
            }
        }
        
        for(int i = 0; i < n; ++i){
            bool row[n +1] = {0}, col[n +1] = {0};
            for(int j = 0; j < n; ++j){
                row[a[i][j]] = 1;
                col[a[j][i]] = 1;
            }
            for(int j = 1; j <= n; ++j){
                if(row[j] == 0){
                    nr++;
                    break;
                }
            }
            for(int j = 1; j <= n; ++j){
                if(col[j] == 0){
                    nc++;
                    break;
                }
            }
        }
        
        cout << "Case #" << test << ": " << ans << " " << nr << " " << nc << endl;
    }
}