#include <bits/stdc++.h>
#define int long long int
#define len length
using namespace std;

int getCount(pair<int, int> p, pair<int, int> q) 
{ 
    if (p.first==q.first) 
        return abs(p.second - q.second) - 1; 
  
    if (p.second == q.second) 
        return abs(p.first-q.first) - 1; 
  
    return __gcd(abs(p.first-q.first), abs(p.second-q.second))-1; 
} 



int32_t main()
{
	int n, x, y;
	cin >> n;
	map<pair<int, int>, int> m;
	for (int i = 0; i < n; ++i)
		cin >> x >> y, m[{x, y}] = i +1;
	cout << m.size() -1 << endl;
	for(int i = 0; i < m.size() -1; ++i){

		cout << "2 " << itr->second << " " << (++itr)->second << endl;
	}
	return 0;
}
