#include<bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int test;
    cin >> test;
    for(int t = 0; t < test; ++t){
        int ans = 0, n, k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i){
            if(a[i] == k){
                int j = 0;
                for(; j < k; ++j, ++i){
                    if(a[i] != k - j){
                        break;
                    }
                }
                if(j == k){
                    ans++;
                }
                --i;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}