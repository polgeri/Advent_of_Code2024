#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void get_vector(string& s, vector<int>& v) {
    stringstream ss(s);
    int x;
    while (ss >> x) v.push_back(x);
}

bool is_safe(vector<int>& v) {
    int n = v.size();
    if (n <= 1) return true;  // If there's only one level, it's automatically safe.

    // Determine whether the sequence is increasing or decreasing
    int dif = v[0] - v[1];

    if(dif== 0) return false;
    
    if (dif<-3 or dif > 3) return false;  // Initial check for difference validity

    if(dif<0){
        for(int i = 1; i<n-1;i++){
            dif = v[i+1]-v[i];
            if(dif>3 or dif<1) return false;
        }
    }
    else {
        for(int i = 1; i<n-1;i++){
            dif = v[i]-v[i+1];
            if(dif>3 or dif<1) return false;
        }
    }
    
    return true;
}

bool is_safe_a_remove(vector<int>& v){
    //cout << "is_safe_a_remove" << endl;
    int n = v.size();
    vector<int> v_copy = v;
    for(int i = 0; i<n; i++){
        v_copy.erase(v_copy.begin()+i);
        if(is_safe(v_copy)) return true;
        v_copy = v;
    }
    return false;
}

int main() {
    string s;
    int safe_report = 0;
    
    while (getline(cin, s)) {
        vector<int> v;
        get_vector(s, v);
        if (is_safe(v)) ++safe_report;
        else if(is_safe_a_remove(v)) ++safe_report;
    }

    cout << safe_report << endl;
    return 0;
}
