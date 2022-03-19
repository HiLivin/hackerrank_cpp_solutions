#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int min(int a, int b){
    return a < b ? a : b;
}

int makeAnagram(string a, string b) {
    int common = 0;
    
    map<char,int> am;
    map<char,int> bm;
    
    map<char,int>::iterator it;
    
    for(int i = 0; i < a.length(); ++i)
        ++am[a[i]];
    
    for(int i = 0; i < b.length(); ++i)
        ++bm[b[i]];
    
    for(it = am.begin(); it != am.end(); ++it)
        common += min(it->second, bm[it->first]);
    
    return a.length() + b.length() - 2 * common;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
