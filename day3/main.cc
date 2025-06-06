#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int count = 0;
    bool enabled = false;
    while(getline(cin,s,')')){
        
        size_t enable = s.find("don't(");
        if(!enabled and enable != string::npos) enabled = true;
        size_t unable = s.find("do(");
        if(enabled and unable != string::npos) enabled = false;

        if(!enabled){
            
            size_t prev_s = s.find("mul(");
            if(prev_s != string::npos){
                size_t start;
                while(prev_s != string::npos){
                    start = prev_s;
                    prev_s = s.find("mul(",start+1);
                }
                size_t coma = s.find(",",start);
                if(coma != string::npos){
                    size_t end = s.size()-1;
                    if(end != string::npos){
                        cout << s << endl;
                        cout << "Start: " << s[start] << " Coma: " << s[coma] << " End: " << s[end] << endl;
                        bool found = false;
                        for(int i = start+4; i < coma and !found; i++){
                            if(s[i] -'0' < 0 || s[i] -'0' > 9){
                                found = true;
                            }
                        }
                        if(!found){
                            for(int i = coma+1; i <= end and !found; i++){

                                if(s[i] -'0' < 0 || s[i] -'0' > 9){
                                    found = true;
                                }
                            }
                        }
                        if(!found){
                            int x = stoi(s.substr(start+4,coma-1),nullptr,10);
                            int y = stoi(s.substr(coma+1,end),nullptr,10);
                            count += (x*y);
                            cout << "X: " << x << " Y: " << y << endl;
                        }
                    }
                    
                }
                
            }
        }    
    }
    cout << count << endl;
}