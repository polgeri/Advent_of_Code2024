#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<string>& board,int i, int j,int count,int& times,int& op){
    if(i<0 ||i>=board.size() ||j<0 || j>board[0].size() || count >3 || (op == 0 && count != 0) ) return ;
    
    if(count == 1){
        if(op == 1){
            if(board[i][j] == 'M') op = 2;
            else op = 0;
        }
        else{
            if(board[i][j] == 'S') op= 1;
            else op = 0;
        }

    }

    else if(count == 3){
        if(op == 1){
            if(board[i][j] == 'M') op= 2;
            else op = 0;
        }
        else{
            if(board[i][j] == 'S') op = 1;
            else op = 0;
        }
    }

    else {
        if ((board[i][j] == 'M' or board[i][j] == 'S')){
            if(board[i][j] == 'S') op = 1;
            else op = 2;
        }
        else op = 0;

    }


    

}

void searchXMAS(vector<string>& board,int r, int c,int& times){
    for(int i = 0; i<r;i++){
        for(int j = 0; j<c; j++){
            if(board[i][j] == 'A'){
                int op= 0;
                dfs(board,i-1,j-1,0,times,op); // adalt esq
                //cout << op << " ";
                dfs(board,i+1,j+1,1,times,op); // abaix dretA
                //cout << op << " ";
                dfs(board,i+1,j-1,2,times,op); // abaix esq
                //cout << op << " ";
                dfs(board,i-1,j+1,3,times,op); // adalt dretA
                //cout << op << " ";
                //cout << endl;
                if(op != 0){
                    ++times;
                }
            
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