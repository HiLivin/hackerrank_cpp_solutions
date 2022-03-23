#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    set<int> s;
    int Q;
    int q;
    int x;
    
    cin >> Q;
    
    for(int i = 0; i < Q; ++i){
        cin >> q >> x;
        
        switch(q){
            case 1:
                s.insert(x);
            break;
            
            case 2:
                s.erase(x);
            break;
            
            case 3:
                if(s.find(x) != s.end())
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            break;
            
            default:
            break;
        }
    }
    
    
    
    return 0;
}



