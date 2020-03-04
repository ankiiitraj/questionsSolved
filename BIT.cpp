#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define debug cout << "Debugging . . .\n";
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
const int N = 100005;

int bit[N] = {0};

void update(int idx, int val){
	for(; idx <= 10; idx += (idx & -idx)){
		bit[idx] += val;
	}
}

int query(int idx){
	int sum = 0;
	for(; idx > 0; idx -= (idx & -idx)){
		sum += bit[idx];
	}
	return sum;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for(int i = 1; i <= 10; ++i){
		update(i, a[i -1
			