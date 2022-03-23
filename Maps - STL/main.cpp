#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    map<string,int> marks;
    int Q;
    int q;
    string x;
    int y;
    
    cin >> Q;
    
    for(int i = 0; i < Q; ++i){
        cin >> q;
        
        switch(q){
            case 1:
                cin >> x >> y;
                marks[x] += y;
            break;
            
            case 2:
                cin >> x;
                marks[x] = 0;
            break;
            
            case 3:
                cin >> x;
                cout << marks[x] << endl;
            break;
            
            default:
            break;
        }
    }
    
     
    return 0;
}
