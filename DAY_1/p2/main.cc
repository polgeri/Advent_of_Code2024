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
        int score = 0;
        int count = 0;
        auto it2 = l2.begin();
        for(auto it1 = l1.begin();it1!=l1.end();it1++){
            for(auto it2 = l2.begin(); it2 != l2.end();++it2){
                if(*it1 == *it2) ++count;
            }
            score += count*(*it1);
            count = 0;
        }
        
        cout << score << endl;
        
}
