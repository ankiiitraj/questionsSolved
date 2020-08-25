#include<bits/stdc++.h>
using namespace std;


int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int t; cin >> t; while(t--){
        int n, k, ones  = 0;
        string s;
        cin >> n >> k >> s;
        for(auto itr: s){
            if(itr == '1'){
                ones++;
            }
        }
        if(ones%(n/k) != 0 or (n - ones)%(n/k) != 0){
            cout << "IMPOSSIBLE\n";
            continue;
        }
            
        int num_blocks = n/k;
        int num_0 = (n - ones)/num_blocks;
        int num_1 = ones/num_blocks;
        
        string res, rev_res,ans;
        for(int i = 0; i < num_0; ++i)
            res += '0';
        for(int i = 0; i < num_1; ++i)
            res +='1';
        
        rev_res = res;
        reverse(rev_res.begin(), rev_res.end());
        for(int i = 0; i < num_blocks; ++i){
            if(i&1){
                ans += rev_res;
            }else{
                ans += res;
            }
        }

        cout << ans << endl;

    }
}