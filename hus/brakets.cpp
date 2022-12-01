#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> res;

void brakets(string s, int i, int n){
    if(s.size() == n){
        if(i==0)
            res.push_back(s);
        return;
    }

    brakets(s+'(', i+1, n);
    if(i>0)
        brakets(s+')', i-1, n);
}

int main(){
    int n;
    cin >> n;
    brakets("(",1,n*2);
    sort(res.begin(), res.end());

    for(string s: res){
        cout << s << endl;
    }

    return 0;
}
