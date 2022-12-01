#include <iostream>
#include <map>

using namespace std;
int a[1502];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m,n;
    cin >> m >> n;
    map<int,int> hd,vd;
    for(int i = 0; i<m; i++){
        cin >> a[i];
        for(int j = 0; j<i; j++){
            hd[a[i]-a[j]]++;
        }
    }
    for(int i = 0; i<n; i++){
        cin >> a[i];
        for(int j = 0; j<i; j++){
            vd[a[i]-a[j]]++;
        }
    }

    long long res = 0;
    for(auto it: hd){
        res += 1ll * it.second * vd[it.first];
    }
    cout << res << endl;

    return 0;
}
