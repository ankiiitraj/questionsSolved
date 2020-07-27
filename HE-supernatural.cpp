    #include<bits/stdc++.h>
    #define int long long 
    using namespace std;
     
     
    signed main(){
        int n, res = 0;
        cin >> n;
        if(n == 1){
            cout << "0\n";
            return 0;
        }
        for(int i = 2; i <= 10000000; ++i){
            int temp = i, cur = 1, flag = 0;
            while(temp){
                cur *= temp%10;
                if(temp%10 == 1){
                    flag = 1;
                    break;
                }
                temp /= 10;
            }
            if(cur == n and !flag){
                // cout << i << endl;
                res++;
            }
        }
        cout << res << endl;
    }