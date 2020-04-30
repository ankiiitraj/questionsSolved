#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353; // 1e9 + 7
const int N = 1000005; // 1e6 +5

/* -------------------------------Solution Sarted--------------------------------------*/

int power(int x, int y){
	if(y == 0)
		return 1;
	if(y&1){
		return (x*power(x, y -1))%MOD;
	}
	int temp = power(x, y/2)%MOD;
	return (temp*temp)%MOD;
}

string InfixToPostfix(string expression)
{
	// Declaring a Stack from Standard template library in C++. 
	stack<char> S;
	string postfix = ""; // Initialize postfix as empty string.
	for(int i = 0;i< expression.length();i++) {

		// Scanning each character from left. 
		// If character is a delimitter, move on. 
		if(expression[i] == ' ' || expression[i] == ',') continue; 

		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if(expression[i] == '&' or expression[i] == '|' or expression[i] == '^') 
		{
			while(!S.empty() && S.top() != '(')
			{
				postfix+= S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		// Else if character is an operand
		else if(expression[i] == '#')
		{
			postfix +=expression[i];
		}

		else if (expression[i] == '(') 
		{
			S.push(expression[i]);
		}

		else if(expression[i] == ')') 
		{
			while(!S.empty() && S.top() !=  '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}



struct score
{
	int z, o, a, A;
	score(){
		z = o = a = A = 748683265;
	}
};

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		string s, postfix;
		cin >> s;
		int n = s.length();
		
		postfix = InfixToPostfix(s);
		// cout << postfix << endl;
		score *Score = new score();
		for(auto itr:postfix){
			int sum = (Score->z + Score->o + Score->a + Score->A)%MOD;
			if(itr == '&'){
				Score->z = (((4*Score->z + 2*Score->a + 2*Score->A + Score->o)%MOD)*power((4*ans)%MOD, MOD -2))%MOD;
				Score->a = ((Score->o + 2*Score->a)*power((4*ans)%MOD, MOD -2))%MOD;
				Score->A = ((Score->o + 2*Score->A)*power((4*ans)%MOD, MOD -2))%MOD;
				// cout << Score->z << " " << Score->o << " " << Score->a << " " << Score->A << " " << sum << endl;
			}else if(itr == '|'){
				Score->o = ((Score->z + 4*Score->o + 2*Score->a + 2*Score->A)*power((4*ans)%MOD, MOD -2))%MOD;
				Score->a = ((Score->z + 2*Score->a)*power((4*ans)%MOD, MOD -2))%MOD;
				Score->A = ((Score->z + 2*Score->A)*power((4*ans)%MOD, MOD -2))%MOD;
			}else if(itr == '^'){
				Score->z = Score->o = Score->a = Score->A = (748683265)%MOD;
			}
		}
		// int total = (Score->z + Score->o + Score->a + Score->A)%MOD;
		
		// int ansZ = ((Score->z/__gcd(Score->z, total))*(power(total/__gcd(Score->z, total), MOD -2)))%MOD;
		// int ansO = ((Score->o/__gcd(Score->o, total))*(power(total/__gcd(Score->o, total), MOD -2)))%MOD;
		// int ansa = ((Score->a/__gcd(Score->a, total))*(power(total/__gcd(Score->a, total), MOD -2)))%MOD;
		// int ansA = ((Score->A/__gcd(Score->A, total))*(power(total/__gcd(Score->A, total), MOD -2)))%MOD;
		
		// cout << ansZ << " " << ansO << " " << ansa << " " << ansA << endl;
		cout << Score->z << " " << Score->o << " " << Score->a << " " << Score->A << "\n";
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
