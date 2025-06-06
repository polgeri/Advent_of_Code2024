
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void get_vector(int n,string s,vector<int>& sol){
    string ss = s;
    int pos=0,aux=0;
    while(aux != -1){
        pos = ss.find_first_not_of(' ');
        ss = ss.substr(pos,string::npos);
        aux = ss.find(' ');
        sol.push_back(strtol(ss.substr(0,aux).c_str(),nullptr,10));
        if(aux != -1) ss = ss.substr(aux,string::npos);
    }
}

bool get_sol(const vector<int>& sol, int idx, long long  &n, long long total){
    if(total == n  and idx == sol.size()) return true;

    if((total<n and idx == sol.size())) {
      //  cout << "molt petit" << endl;
        return false;
    
    }

    if(total > n){
    //    cout << "molt gran" << endl;
        return false;
    }
    for(int i = 0; i<2; i++){
        long long value;
        if(idx == 0) value = sol[idx];
        else if(i == 0) value = total * sol[idx];
        else if (i == 1) value = total + sol[idx]; 
        //cout << "value: " << value << " i: " << i << " total: " << total << endl;
        //cout << "sol.size " << sol.size() << " idx: " << idx << endl;
        if(get_sol(sol,idx+1,n,value)) return true;
    }

    return false;
}


int main(){
    string s;
    long long result=0;
    while(getline(cin,s,':')){
        long long n = strtol(s.c_str(),nullptr,10);
        getline(cin ,s);
        vector<int> sol;
        get_vector(n,s,sol);
        if(get_sol(sol,0,n,0)) {
            result += n;
            cout << result << endl;
            cout << n << endl;

        }
    }
    cout << "Resultat: " << result << endl;
    //cout << 2314935962622-1703592819 << endl;
}