#include<bits//stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int t; cin >> t; for(int test = 1; test <= t; ++test){
        int n, a, b, c, flag = 0;
        vector<int> res;
        cin >> n >> a >> b >> c;
        int new_n = n;
    
        a -= c;
        b -= c;
        n -= a + b + c;
        for(int i = 0; i < a; ++i)
            res.push_back(2);

        res.push_back(new_n);
        
        for(int i = 0; i < n; ++i)
            res.push_back(1);
        
        for(int i = 0; i < c -1; ++i)
            res.push_back(new_n);
        
        for(int i = 0; i < b; ++i)
            res.push_back(2);
        
        if(res.size() != new_n){
            cout << "Case #" << test << ": IMPOSSIBLE\n";
        }else{
            cout << "Case #" << test << ": ";
            for(auto itr: res){
                cout << itr << " ";
            }
            cout << endl;
        }
    }
}