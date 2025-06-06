#include <list>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;


int main(){
    int n1,n2;
    list<int> l1,l2;    
    while(cin >> n1 >> n2){
        l1.push_back(n1);
        l2.push_back(n2);
    }
        l1.sort();
        l2.sort();
        int distance = 0;
        auto it2 = l2.begin();
        
        for(list<int>::iterator it1 = l1.begin(); it1 != l1.end(); it1++){
            distance += abs(*it1 - *it2);
            ++it2;
        }
        
        cout << distance << endl;
        
}
