#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#define fori(i,a,b) for(int i = a; i<b; i++)
#define MAXN 500002
#define ll long long

using namespace std;

int a[MAXN], loc[MAXN];
int n,m;

void lshift(int value){
    for(int i = loc[value]; i>1; i--){
        a[i] = a[i-1];
        loc[a[i]] = i;
    }
    a[1] = value;
    loc[value] = 1;
}

void rshift(int value){
    for(int i = loc[value]; i<n; i++){
        a[i] = a[i+1];
        loc[a[i]] = i;
    }
    a[n] = value;
    loc[value] = n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    fori(i,1,n+1){
        cin >> a[i];
        loc[a[i]] = i;
    }

    ll total = 0;
    int x;
    char q;
    while(m--){
        cin >> x >> q;
        total += min(loc[x]-1,n-loc[x]);
        if(q == 'l')
            lshift(x);
        else
            rshift(x);
    }

    cout << total << endl;

    return 0;
}
