#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<string>& board,int r, int c,int count,int& times,int h,int v){
    if(r<0 ||r>=board.size() ||c<0 || c>board[0].size() || count >3 ) return;
    

    if (count == 1 && board[r][c] != 'M') return ;
    if (count == 2 && board[r][c] != 'A') return;
    if (count == 3 && board[r][c] != 'S') {
        return;
    } else if (count == 3 && board[r][c] == 'S') {
        ++times;
        return ;
    }

    ++count;

    dfs(board,r+v,c+h,count,times,h,v);
    
}

void searchXMAS(vector<string>& board,int r, int c,int& times){
    for(int i = 0; i<r;i++){
        for(int j = 0; j<c; j++){
            if(board[i][j] == 'X'){
                dfs(board,i,j,0,times,1,0); // dreta
                dfs(board,i,j,0,times,-1,0); // esq
                dfs(board,i,j,0,times,0,1); // adalt
                dfs(board,i,j,0,times,0,-1); // abaix
                dfs(board,i,j,0,times,-1,-1); // esq abaix
                dfs(board,i,j,0,times,1,1); // dreta adalt
                dfs(board,i,j,0,times,1,-1); // dreta abaix
                dfs(board,i,j,0,times,-1,1); // esq adalt
            
            }
        }
    }
}

int main(){
    vector<string> board;
    int i = 0;
    string s;
    while(getline(cin,s)){
            board.push_back(s);
    }

    int r =board.size();
    int c = board[0].size();
    int times = 0;
    searchXMAS(board,r,c,times);
    cout << times << endl;
}






/*for(int i = 0; i<r;i++){
        for(int j = 0; j<c-1; j++){
            cout << m[i][j];
        }
        cout << endl;
    }
    cout << endl;
    */