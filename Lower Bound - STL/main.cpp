#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    int Q;
    int Y;
    vector<int> X;
    vector<int>::iterator it;
    
    cin >> N;
    
    for(int i = 0; i < N; ++i){
        int tmp;
        cin >> tmp;
        X.push_back(tmp);
    }
    cin >> Q;
    
    for(int i = 0; i < Q; ++i){
        cin >> Y;
        
        it = lower_bound(X.begin(), X.end(), Y);
        
        if(*it == Y){
            cout << "Yes " << it - X.begin() + 1 << endl;
        }else{
            cout << "No " << it - X.begin() + 1 << endl;
        }
    }
    
    
    
    return 0;
}
