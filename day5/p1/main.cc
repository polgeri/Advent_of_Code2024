#include <iostream>
#include <vector> 
#include <string>
#include <unordered_set>
using namespace std;


bool is_correctly_ordered(vector<vector<int>>& adj, vector<int> page_update){
    unordered_set<int> visited;
    for (int i = 0; i < page_update.size(); ++i) {
        for (int neighbour : adj[page_update[i]]) {
            if (visited.count(neighbour)) return false;
        }
        visited.insert(page_update[i]);
    }
    return true;
}


int main(){
    int n = 100;
    vector<vector<int>> adj(n);
    string s;
    getline(cin ,s);
    while(s.find('|') != string::npos){
        int x = stoi(s,nullptr,10);
        int pos = s.find("|");
        int y = stoi(s.substr(pos+1),nullptr,10);
        adj[x].push_back(y);
        getline(cin,s);
    }
    int add_up = 0;
    while(getline(cin,s)){
        vector<int> page_update;
        string ss = s;
        bool end = false;
        bool activate = false;
        while(!end){
            if(activate) end = true;

            int x = stoi(ss,nullptr,10); 
            cout << x << endl;
            page_update.push_back(x);
            
            ss = ss.substr(ss.find(',')+1);
            if(ss.find(',') == string::npos) activate = true;
        }
        if(is_correctly_ordered(adj,page_update)){
            int pos = page_update.size()/2;
            add_up += page_update[pos];
        }
    }
    cout << add_up << endl;

}