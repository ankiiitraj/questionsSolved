#include <bits/stdc++.h>
using namespace std;

//recursive tail optimised
int fib(int n, int acc, int last, int req){
	if(n >= req){
		return last;
	}
	return fib(n +1, acc + last, acc, req);
}

int fibo(int n){
	if(n == 0 or n == 1)
		return 1;
	return fibo(n - 1) + fibo(n -2);
}
// 1, 1, 2, 3, 5, 8, 13, 21, 34
int main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    for(int i = 1; i <= 20; ++i){
		cout << "(" << fib(0, 1, 1, i) << " ";
		cout << fibo(i) << ") ";

    }
	return 0;
}