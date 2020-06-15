#include <bits/stdc++.h>
#define int long long int
using namespace std;

bool divisibility(int a, int b){
	if(b == 0){
		return 0;
	}
	if(a%b==0)
		return 1;
	return 0;
}

bool add2times(int x, int y, int z, int p, int q, int r){
	if(y - (q + x - p) == z - r || z - (r + x - p) == y - q)
		return 1;
	return 0;
}
bool multiply2times(int x, int y, int z, int p, int q, int r){
	if(divisibility(x, p) && divisibility(y, (q*(x/p))) && divisibility(z, r) && divisibility(y, q*(z/r)) && (y/(q*(x/p)) == z/r || y/(q*(z/r)) == x/p))
		return 1;
	return 0;
	if(divisibility(x, p)){
		int cur = x/p;
		if(divisibility(y, cur) && divisibility(z, r) && y/cur == z/r){
			return 1;
		}else if(divisibility(z, cur) && divisibility(y, q) && z/cur == y/q){
			return 1;
		}
	}
	return 0;
}
bool add_multiply(int p, int x, int q, int y, int r, int z){
	if(divisibility(q*x - p*y, y - x)){
		int a = (q*x - p*y)/(y - x);
		if(divisibility(x, p + a)){
			int b = x/(p + a);
			if((r + a)*b == z){
				return 1;
			} 
		}
	}
	return 0;
}
bool multiply_add(int p, int x, int q, int y, int r, int z){
	if(divisibility(x - y, p - q)){
		int a = (x - y)/(p - q);
		int b = x - p*a;
		if(r*a + b == z)
			return 1;
	}
	return 0;
}
bool add_2_multiply_2(int p, int x, int q, int y, int r, int z){
	int added = x - p;
	if(divisibility(z, r) && (q + added)*(z/r) == y)
		return 1;
	if(divisibility(y, q) && (r + added)*(y/q) == z)
		return 1;
	return 0;
}
bool add_3_multiply_2(int p, int x, int q, int y, int r, int z){
	int added = x - p;
	if(divisibility(z, r + added) && divisibility(y, q + added) && z/(r + added) == y/(q + added) )
		return 1;
	return 0;
}
bool multiply_3_add_2(int p, int x, int q, int y, int r, int z){
	if(divisibility(x, p)){
		int mul = x/p;
		if(y - (q*mul) == z - (r*mul))
			return 1;
	}
	return 0;
}
bool mul_2_add_2(int p, int x, int q, int y, int r, int z){
	if(divisibility(x, p)){
		int mul = x/p;
		if(y - (q*mul) == z - r)
			return 1;

		if(y - q == z - r*mul)
			return 1;
	}
	return 0;
}

int32_t main()
{
	int t; 
	cin >> t; 
	while(t--){
		int p, q, r, x, y, z;
		cin >> p >> q >> r >> x >> y >> z;

		int ans;

		if(p == x && q == y && r == z){
			ans = 0;
		}else if((p == x && q == y) || (p == x && z == r) || (q == y && r == z) || ((p == x && (q - y == r - z || (divisibility(y, q) && divisibility(z, r) && y/q == z/r))) || (q == y && (p - x == r - z || (divisibility(x, p) && divisibility(z, r) && x/p == z/r))) || (r == z && (q - y == p - x || (divisibility(y, q) && divisibility(x, p) && y/q == x/p)))) || ((x - p) == (y - q) && (y - q) == (z - r)) || (divisibility(x, p) && divisibility(y, q) && divisibility(z, r) && (x/p == y/q && y/q == z/r))){
			ans = 1;
		}else if((p == x || q == y || r == z) || ((x - p == y - q) || (x - p == z - r) || (y - q == z - r) || (divisibility(x, p) && (divisibility(y, q) && x/p == y/q)) || (divisibility(x, p) && (divisibility(z, r) && x/p == z/r)) || (divisibility(z, r) && (divisibility(y, q) && z/r == y/q))) || (add2times(x, y, z, p, q, r) || add2times(z, x, y, r, p, q) || add2times(y, z, x, q, r, p)) || (multiply2times(x, y, z, p, q, r) || multiply2times(z, x, y, r, p, q) || multiply2times(y, z, x, q, r, p)) || (add_multiply(p, x, q, y, r, z)) || ((divisibility(x, p) && (divisibility(y*r - z*q, z - y)) && (q + (y*r - z*q)/(z - y))*(x/p) == y && (r + (y*r - z*q)/(z - y))*(x/p) == z) || (divisibility(y, q) && (divisibility(x*r - z*p, z - x)) && (p + (x*r - z*p)/(z - x))*(y/q) == x && (r + (x*r - z*p)/(z - x))*(y/q) == z) || (divisibility(z, r) && (divisibility(x*q - y*p, y - x)) && (p + (x*q - y*p)/(y - x))*(z/r) == x && (q + (x*q - y*p)/(y - x))*(z/r) == y)) || (add_3_multiply_2(p, x, q, y, r, z) || add_3_multiply_2(q, y, p, x, r, z) || add_3_multiply_2(r, z, q, y, p, x)) || (add_2_multiply_2(p, x, q, y, r, z) || add_2_multiply_2(q, y, p, x, r, z) || add_2_multiply_2(r, z, p, x, q, y)) || multiply_add(p, x, q, y, r, z) || ((divisibility(y - q - (x - p), q) && divisibility(z - r - (x - p), r) && (y - q - (x - p))/q == (z - r - (x - p))/r)) || ((divisibility(y - q - (z - r), q) && divisibility(x - p - (z - r), p) && (y - q - (z - r))/q == (x - p - (z - r))/p)) || ((divisibility(x - p - (y - q), p) && divisibility(z - r - (y - q), r) && (x - p - (y - q))/p == (z - r - (y - q))/r)) || (multiply_3_add_2(p, x, q, y, r, z) || multiply_3_add_2(q, y, p, x, r, z) || multiply_3_add_2(r, z, p, x, q, y)) || (mul_2_add_2(p, x, q, y, r, z) || mul_2_add_2(q, y, p, x, r, z) || mul_2_add_2(r, z, p, x, q, y))){
			ans = 2;
		}else{
			ans = 3;
		}
		cout << ans << endl;

	}
	return 0;
}
