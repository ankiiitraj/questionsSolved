#include<bits/stdc++.h>
using namespace std;


int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int t; cin >> t; while(t--){
        string x;
        cin >> x;
        int n = x.length();
        if(n&1){
            cout << "-1\n";
            continue;
        }
        stack<int>s;
        for(int i = 0; i < n; ++i){
            if(x[i] == '{'){
                s.push(i);
            }else{
                if(!s.empty()){
                    x[i] = '.';
                    x[s.top()] = '.';
                    s.pop();
                }
            }
        }
        int clo = 0, open = 0;
        for(auto itr: x){
            if(itr == '}')
                clo++;
            else if(itr == '{')
                open++;
        }
        
        cout << (ceil((float)clo/2) + ceil((float)open/2)) << endl;
        
    }
}