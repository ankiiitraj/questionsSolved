#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string s, int i, int j){
    while(i <= j){
        if(s[i] != s[j])
            return 0;
        ++i, --j;
    }
    return 1;
}
void helper(string &s, int i, int j, vector<string> &cur, vector<vector<string>> &res){
    if(i >= j){
    	if(i == j){
	        cur.push_back(s.substr(i, 1));
	        res.push_back(cur);
	        cur.pop_back();
    	}else{
	        res.push_back(cur);
    	}
        return;
    }
    
    for(int k = i; k <= j; ++k){
        if(is_palindrome(s, i, k)){
            cur.push_back(s.substr(i, k - i +1));
            helper(s, k +1, j, cur, res);
        	cur.pop_back();
        }
    }
    
}

vector<vector<string>> partition(string s){
    vector<string> cur;
    vector<vector<string>> res;
    helper(s, 0, s.length() -1, cur, res);
    return res;
}

int main(){
//#ifndef ONLINE_JUDGE
//    freopen("ip.txt", "r", stdin);
//    freopen("op.txt", "w", stdout);
//#endif
	string s;
	cin >> s;
	vector<vector<string>> res = partition(s);
	
    for(auto itr: res){
    	for(auto it: itr){
    		cout << it << " ";
    	}
    	cout << endl;
    }
}
