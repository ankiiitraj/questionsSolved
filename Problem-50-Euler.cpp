// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//                               Author : Ankit Raj
//                      Problem Name    :    Number spiral diagonals
//         		Problem Link : https://projecteuler.net/problem=28
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define debug cout << "Debugging . . .\n";
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

vector<bool> isPrime(1000, 0);
vector <int> primes;

void sieve(){
	isPrime[1] = isPrime[0] = 1;
	for(int i = 2; i*i <= 1000; ++i){
		if(isPrime[i] == 0){
			for(int j = i*i; j <= 1000; j += i){
				isPrime[j] = 1;
			}
		}
	}
	for(int i = 0; i < 1000; ++i)
		if(isPrime[i] == 0)
			primes.push_back(i);
}

int32_t main()
{
	faster;
	sieve();
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t;cin >> t;while (t--) 
	// {
	// 	for(int i = primes.size() -1; i >= 0; --i){
	// 		int cur = primes[i];
	// 		for(int j = 0; j < primes.size(); ++j){
	// 			cur -= primes[j];
	// 			if(cur == 0){
	// 				cout << primes[i] << endl;
	// 				goto ans;
	// 			}else if(cur < 0){
	// 				break;
	// 			}

	// 		}
	// 	}
	int ans = 0, prime, len = INT_MIN;

	// for(int i = primes.size() -1; i >= 0; --i){
		// cout << primes[i] << " ";
		for(int j = 0; j < primes.size(); ++j){
			ans = 0;
			for(int k = j; k < primes.size(); ++k){
				ans += primes[k];
				if(ans == 953){
					if(len < k - j +1){
						len = k - j + 1;
						for(int l = j; l <= k; ++k)
							cout << primes[l] << " ";
						prime = 953;
					}
					break;
				}else if(ans > 953){
					break;
				}
			}
			
		}
	// }
	cout << len << " " << prime << endl;
}