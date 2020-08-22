#include<bits/stdc++.h>
#include<time.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back

int main(){
#ifndef ONLINE_JUDGE
    freopen("op.txt", "r", stdin);
    freopen("ip.txt", "w", stdout);
#endif
    srand(time(0));
    // int t = 1000;
    // cout << t << endl;
    // while(t--){
        int n = 30;
        int t = rand()%1000000 +1000;
        cout << n << " " << t << endl; 
        for(int i = 0; i < n; ++i){
            cout << ((int)rand()%100) << " ";
        }
        cout << endl;
        for(int i = 0; i < n; ++i){
            cout << ((int)rand()%100) << " ";
        }
        cout << endl;
    // }

}