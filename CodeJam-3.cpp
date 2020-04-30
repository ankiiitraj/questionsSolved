#include<bits/stdc++.h>
using namespace std;

struct triple{
    int first, second, third;
};

bool cmp(triple &t1, triple &t2){
    return t1.first < t2.first;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("ip.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
// #endif
    int t; cin >> t;
    for(int test = 1; test <= t; ++test){
        string ans = "IMPOSSIBLE", s;
        int n, flag = 0;
        cin >> n;
        vector<triple> acts(n);
        for(int i = 0; i < n; i++){
            s += '0';
            cin >> acts[i].first >> acts[i].second;
            acts[i].third = i;
        }
        
        sort(acts.begin(), acts.end(), cmp);

        bool c = 0, f = 0;
        int fends = -1, cends = -1;
        for(int i = 0; i < n; ++i){
            if(acts[i].first >= fends){
                f = 0;
            }
            if(acts[i].first >= cends){
                c = 0;
            }
            if(!f){
                f = 1;
                s[acts[i].third] = 'J';
                fends = acts[i].second;
            }else if(!c){
                c = 1;
                s[acts[i].third] = 'C';
                cends = acts[i].second;
            }else{
                flag = 1;
                break;
            }
        }
        cout << "Case #" << test << ": " << (flag ? ans : s) << endl;
    }
}