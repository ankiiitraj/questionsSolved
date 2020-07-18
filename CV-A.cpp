#include<bits/stdc++.h>
using namespace std;


int main(){
// #ifndef ONLINE_JUDGE
//   freopen("ip.txt", "r", stdin);
//   freopen("op.txt", "w", stdout);
// #endif
  int n, r = 0, m = 0, res = 0;
  string s1, s2;
  cin >> n >> s1 >> s2;
  
  for(int i = 0; i < n; ++i){
    if(s2[i] == 'r'){
      r++;
    }else{
      m++;
    }
  }
  
  for(int i = 0; i < n; ++i){
	if(s1[i] == 'r'){
		if(r > 0)
          r--, res++;
      	else
          break;
    }else{
      if(m > 0)
          m--, res++;
      	else
          break;
    }
  }
    
    cout << n - res;

}