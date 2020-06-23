#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5
#define MAXN   10000001 

/* -------------------------------Solution Sarted--------------------------------------*/
int spf[MAXN]; 

void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  		spf[i] = i; 
  
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 

int getFactorization(int x) 
{ 
    set<int> ret; 
    bool flag = 0;
    int temp = x;
    while (x != 1) 
    { 
        ret.insert(spf[x]); 
        if(ret.size() >= 2){
        	flag = 1; 
        	break;
        }
        x = x / spf[x]; 
    }

    return (*ret.begin());

} 


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	{
		sieve();
		int n;
		cin >> n;
		vi a(n);
		scnarr(a, n);
		vector<pii> ans;
		for(auto itr: a){
			if(itr&1){
				int i = getFactorization(itr);
				while(itr%i == 0){
					itr /= i;
				}
				if(itr != 1){
					ans.push_back({i, itr});
				}else{
					ans.push_back({-1, -1});
				}
			}else{
				while(itr%2 == 0){
					itr /= 2;
				}
				if(itr != 1){
					ans.push_back({2, itr});
				}else{
					ans.push_back({-1, -1});
				}
			}
		}
		for(auto itr: ans)
			cout << itr.first << " ";
		cout << endl;
		for(auto itr: ans)
			cout << itr.second << " ";
		cout << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	