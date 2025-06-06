#include <iostream>
#include <vector> 
#include <string>
#include <unordered_set>
#include <queue>
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

vector<int> topological_sort(vector<vector<int>>& adj,vector<int> page_update){
    vector<int> inDegree(adj.size(),0);
    vector<int> ordered_pages;
    queue<int> q;
    int n = page_update.size();

    for(int i = 0; i<n;i++){
        for(int neighbour: adj[page_update[i]]) {
            inDegree[neighbour]++;
        }
    }

    for(int i = 0; i<n; i++){
        if(inDegree[page_update[i]] == 0) q.push(page_update[i]);
    }

    while(!q.empty()){

        int node = q.front();
        q.pop();
        ordered_pages.push_back(node);

        for(int neighbour: adj[node]){
            inDegree[neighbour]--;
            bool found = false;
            for(int i= 0;i<n and !found;i++){
                if(page_update[i] == neighbour) found = true;
            }
            if(inDegree[neighbour] ==  0 and found) q.push(neighbour);
        }
        
    }
    cout << "in_top_srot " << endl;
    for(int i : page_update) cout << i << " ";
    cout << endl;
    cout << "ordered v: " << endl;
    for(int i: ordered_pages) cout << i << " ";
    cout << endl;
    return ordered_pages;

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
            page_update.push_back(x);
            
            ss = ss.substr(ss.find(',')+1);
            if(ss.find(',') == string::npos) activate = true;
        }
        if(!is_correctly_ordered(adj,page_update)){
            cout << "no ordered: " << " ";
            for(int i : page_update) cout << i << " ";
            cout << endl;
            page_update = topological_sort(adj,page_update);
            int pos = page_update.size()/2;
            add_up += page_update[pos];
            cout << add_up << endl;
        }
    }
    cout << add_up << endl;

}