#include<bits/stdc++.h>
using namespace std;

struct node{
    node *chars[26];
    bool ends;
    node(){
        for(int i = 0; i < 26; ++i)
            chars[i] = NULL;
        ends = 0;
    }
};

node *head = NULL;
set<string> res;

void insert(string s){
    node *itr = head;
    for(int i = 0; i < s.length(); ++i){
        if(itr->chars[s[i] - 'a'] == NULL){
            itr->chars[s[i] - 'a'] = new node();
        }

        itr = itr->chars[s[i] - 'a'];
    }

    itr->ends = 1;
    
}

void print(node *root, string q){
    if(root->ends){
        res.insert(q);
    }
    for(int i = 0; i < 26; ++i){
        if(root->chars[i]){
            q += (i + 'a');
            print(root->chars[i], q);
            q.pop_back();
        }
    }
}

void query(string q){
    res.clear();
    node *itr = head;
    for(int i = 0; i < q.length(); ++i){
        if(itr->chars[q[i] - 'a'] == NULL){
            cout << "0\n";
            return;
        }
        itr = itr->chars[q[i] - 'a'];
    }
    print(itr, q);

    for(auto itr: res){
        cout << itr << " ";
    }
    cout << endl;
    
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int t; cin >> t; while(t--){
        int n;
        cin >> n;
        string s, q;
        head = new node();
        for(int i = 0; i < n; ++i){
            cin >> s;
            insert(s);
        }
        cin >> q;
        for(int i = 1; i <= q.length(); ++i){
            query(q.substr(0, i));
        }
        
    }
}