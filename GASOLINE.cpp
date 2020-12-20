#include <iostream>
#include <map>
#include <stack>
using namespace std;

int main(){
	map<string, map<string, string>>table;
	map<string, string>asso;
	map<string, int>prec;
	string oper[] = {"+", "-", "*", "^", "id", "$"};

	asso["$"] = "N";
	for (int i = 0; i < 5; i++){
		cout << "Associativity of " << oper[i] << " is L or R" << "\n";
		cin >> asso[oper[i]];
	}

	for (int i = 0; i < 6; i++){
		cout << "Precedence of " << oper[i] << " is" << "\n";
		cin >> prec[oper[i]];
	}

	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			if (oper[i] == oper[j]){
				if (oper[i] == "id" || oper[i] == "$"){
					table[oper[i]][oper[i]] =  ".";
				}
				else{
					if (asso[oper[i]] == "L"){
						table[oper[i]][oper[i]] =  ">";
					}
					else{
						table[oper[i]][oper[i]] =  "<";
					}
				}
			}
			else{
				if(prec[oper[i]] > prec[oper[j]]){
					table[oper[i]][oper[j]] =  ">";
				}
				else{
					table[oper[i]][oper[j]] =  "<";
				}
			}
		}
	}

	cout << "   ";
	for (int i = 0; i < 6; i++)
		cout << oper[i] << " ";
	cout << "\n";

	for (int i = 0; i < 6; i++){
		cout << oper[i] << " ";
		if (oper[i] != "id") cout << " ";
		for (int j = 0; j < 6; j++){
			cout << table[oper[i]][oper[j]] << " ";
			if (oper[j] == "id") cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
