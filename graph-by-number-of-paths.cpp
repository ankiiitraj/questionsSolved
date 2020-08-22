#include<bits/stdc++.h>
#define int long long
using namespace std;

string to_binary(int n){
	string res;
	while(n){
		res += (char)(n%2 + '0');
		n /= 2;
	}
	return res;
}

signed main(){
	int n;
	cin >> n;
	if(n == 1){
		cout << "2 1\n1 2\n";
		return 0;
	}
	int num_nodes = 130, num_edges = 0;
	int arr[131];
	vector<int> adj[num_nodes +1];
	string s = to_binary(n);
	int src = 1, sink = 130;
	int num_of_bits = s.length();
	int num_of_layers = num_of_bits -1;
	int node_id = 2;
	adj[src].push_back(2); adj[src].push_back(3);
	num_edges++;num_edges++;
	for(int i = 1; i <= num_of_layers -1; ++i){
		adj[node_id].push_back(node_id +2);
		adj[node_id +1].push_back(node_id +2);
		adj[node_id].push_back(node_id +3);
		adj[node_id +1].push_back(node_id +3);
		num_edges += 4;
		if(s[i -1] == '1'){
			adj[node_id].push_back(sink);
			num_edges++;
		}
		node_id += 2;
	}
	if(s[num_of_layers -1] == '1'){
		adj[node_id].push_back(node_id +1);
		num_edges++;
	}
	adj[node_id].push_back(sink); adj[node_id +1].push_back(sink);
	num_edges += 2;
	cout << num_nodes << " " << num_edges << endl;
	for(int i = 1; i <= num_nodes; ++i){
		if(adj[i].size() > 0){
			for(auto itr: adj[i]){
				cout << i << " " << itr << endl;
			}
		}
	}

}