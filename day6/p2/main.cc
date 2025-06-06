#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

pair<int,int> find_guard(vector<string>& board){
    int n = board.size( );
    int m = board[0].size( );

    for(int i = 0; i<n ;i++){
        for(int j = 0; j<m ; j++){
            if(board[i][j] == '^') {
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

void path_guard(vector<string>& board,vector<vector<bool>>& visited,stack<pair<int,int>>& path, pair<int,int>& pos_guard,int i, int j, bool& found, int mode , int& num){
    if(pos_guard.first+i<0 ||pos_guard.first+i > board.size() || pos_guard.second+j <0 || pos_guard.second+j > board[0].size() || board[pos_guard.first+i][pos_guard.second+j] == '#' ||found) return;

    pos_guard.first = pos_guard.first+i;
    pos_guard.second = pos_guard.second+j;

    //cout <<  "pos: " <<pos_guard.first << " " << pos_guard.second << endl;
    //cout << "prev: " << board[pos_guard.first][pos_guard.second] << endl;
    if(mode == 0) path.push(pos_guard);
    else {
        if(visited[pos_guard.first][pos_guard.second]){
            ++num;
            //cout << num << endl;
        }
        visited[pos_guard.first][pos_guard.second] = true;
    }
    
    if(pos_guard.first == 0 || pos_guard.first == board.size()-1 || pos_guard.second == 0 || pos_guard.second == board[0].size()-1 ){
        //cout << "found :"<<found << endl;
        found = true;
        return;
    }

    path_guard(board,visited,path,pos_guard,i,j,found,mode,num);

}

void path_guard_helper(vector<string>& board,stack<pair<int,int>>& path,pair<int,int>& pos_guard, int n,int m, int mode,bool& found){
    found = false;
    int num = 0;
    pair<int,int> pos_guard_aux = pos_guard;
    vector<vector<bool>> visited (n,vector<bool> (m,false));
    while(!found and num <= 1000){
       // cout << "adalt: " << endl;
        path_guard(board,visited,path,pos_guard_aux,-1,0,found,mode,num); // adalt
        //cout << "dreta: " << endl;
        path_guard(board,visited,path,pos_guard_aux,0,1,found,mode,num); // dreta
        //cout << "abaix: " << endl;
        path_guard(board,visited,path,pos_guard_aux,1,0,found,mode,num); // 
        //cout << "esq: " << endl;
        path_guard(board,visited,path,pos_guard_aux,0,-1,found,mode,num);
    }
    //cout << "resutl: " << endl;
   /* while(path.size() >0){
        cout << path.top().first << " " << path.top().second << endl;
        path.pop();
    }*/
}

bool find_loop(vector<string>& board,stack<pair<int,int>>& path,pair<int,int>& pos_guard, int n,int m, bool& found){
    path_guard_helper(board,path,pos_guard,n,m,1,found);
    
    if(found) return false;
    else return true;
}

int hm_loop(vector<string>& board,stack<pair<int,int>>& path,pair<int,int>& pos_guard, int n,int m, bool& found){
    int count = 0;
    vector<vector<bool>> visited(n,vector<bool> (m,false));
    while(!path.empty()){
        found = false;
        if(board[path.top().first][path.top().second] != '^' and !visited[path.top().first][path.top().second]){
            //cout << "find_loop: " << path.top().first << " " << path.top().second << endl;
            board[path.top().first][path.top().second] = '#';
            if(find_loop(board,path,pos_guard,n,m,found)) count++;
            visited[path.top().first][path.top().second] = true;
            board[path.top().first][path.top().second] = '.';
        }
        path.pop();
        //cout << path.top().first << " " << path.top().second << endl;
    }
    return count;
}

int main(){
    string s;
    vector<string> board;
    while(getline(cin,s)){
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c) {return !isprint(c); }), s.end());
        board.push_back(s);
    }

    int n = board.size( );
    int m = board[0].size( );

    pair<int,int> pos_guard = find_guard(board);
    stack<pair<int,int>> path;
    bool found = false;

    path_guard_helper(board,path,pos_guard,n,m,0,found);
    int count = hm_loop(board,path,pos_guard,n,m,found);

    cout << endl;
    cout << count << endl;
    
    /*for(int i = 0; i<n ;i++){
        for(int j = 0; j<m ;j++){
            cout << board[i][j];
        }
        cout << endl;
    }*/
}