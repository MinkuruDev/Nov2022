#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#define fori(i,a,b) for(int i = a; i<b; i++)
#define MAXN 300002
#define ll long long

using namespace std;

ll a[MAXN];

ll get(int l, int r) {
    return a[r] - a[l-1];
}
    

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n2,n; cin >> n; n2 = n*2;
    a[0] = 0;
    fori(i,1,n2+1){
        cin >> a[i];
        // a[i] += a[i-1];
    }

    ll res = 0;

    // 1 2 3 4 5 6 7 8 9 10
    fori(i,1,n2){
        int l,r;
        if(i%2==1){
            l = i+1;
        }else{
            l = i+2;
        }
        r = min(l+n, n2);

        fori(j,l,r+1){
            res += abs(a[i]-a[j]);
            res %= 998244353;
        }
    }

    cout << (res * 2) % 998244353 << endl;

    return 0;
}