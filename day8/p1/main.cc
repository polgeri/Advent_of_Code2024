#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


bool char_valid(char x, vector<char> &chars_visited){
    for(char c : chars_visited){
        if(x == c) return false;
    }
    return true;
}

void node_counter(vector<string> &board, int i, int j, vector<vector<bool>> & visited, int &count){

}

int main(){
    string s;
    vector<string>board;
    while(getline(cin,s)){
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c) {return !isprint(c); }), s.end()); //remove all non-printable characters from string s
        board.push_back(s);
    }

    int row = board.size()-1;
    int column = board[0].size()-1;

    vector<vector<bool>> visited(row,vector<bool>(column,false));

    int count=0;

    for(int i = 0; i<=row; i++){
        for(int j = 0; j<=column; j++){
            if(board[i][j] != '.') {
                //cout << i << " " << j << endl;
                node_counter(board,i,j,visited,count);
            }
            }
    }

    cout << "count: " << count << endl;

}