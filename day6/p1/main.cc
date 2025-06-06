#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

void path_guard(vector<string>& board,vector<vector<bool>>& visited, pair<int,int>& pos_guard,int i, int j,bool& found, int& count){
    if(pos_guard.first+i<0 ||pos_guard.first+i > board.size() || pos_guard.second+j <0 || pos_guard.second+j > board[0].size() || board[pos_guard.first+i][pos_guard.second+j] == '#') return;

    pos_guard.first = pos_guard.first+i;
    pos_guard.second = pos_guard.second+j;

    cout <<  "pos: " <<pos_guard.first << " " << pos_guard.second << endl;
    cout << "prev: " << board[pos_guard.first][pos_guard.second] << endl;
    
    if(!visited[pos_guard.first][pos_guard.second]){
        visited[pos_guard.first][pos_guard.second] = true;
        ++count;
    }

    board[pos_guard.first][pos_guard.second] = 'X';



    
    if(pos_guard.first == 0 || pos_guard.first == board.size()-1 || pos_guard.second == 0 || pos_guard.second == board[0].size()-1 ){
        cout << found << endl;
        found = true;
        return;
    }

    path_guard(board,visited,pos_guard,i,j,found,count);

}

int path_guard_helper(vector<string>& board,pair<int,int>& pos_guard, int n,int m){
    bool found = false;
    vector<vector<bool>> visited(n,vector<bool> (m,false));
    int count = 0;
    while(!found){
        cout << "adalt: " << endl;
        path_guard(board,visited,pos_guard,-1,0,found,count); // adalt
        cout << "dreta: " << endl;
        path_guard(board,visited,pos_guard,0,1,found,count); // dreta
        cout << "abaix: " << endl;
        path_guard(board,visited,pos_guard,1,0,found,count); // 
        cout << "esq: " << endl;
        path_guard(board,visited,pos_guard,0,-1,found,count);
    }
    cout << "resutl: " << endl;
        for(int i = 0; i<n ;i++){
        for(int j = 0; j<m ;j++){
            cout << board[i][j];
        }
        cout << endl;
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
    int count = path_guard_helper(board,pos_guard,n,m);
    cout << endl;
    
    for(int i = 0; i<n ;i++){
        for(int j = 0; j<m ;j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << count << endl;
}