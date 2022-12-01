#include <iostream>
#include <set>

using namespace std;

int a[1'000'002];

int solve(int n){
    set<int> siuuuuu;
    int res = 0, i1=0, j1=0, i2=0, j2=0;
    while(i1 < n){
        while(j1<n && siuuuuu.insert(a[j1]).second)
            j1++;
        i2 = j1 + 1;

        while(i2 < n){
            while(i2<n && !siuuuuu.insert(a[i2]).second)
                i2++;
            j2 = i2 + 1;
            while(j2<n && siuuuuu.insert(a[j2]).second)
                j2++;

            res = max(res, (j1-i1) + ((i2<n)? (j2-i2) : 0));

            while(i2 < j2)
                siuuuuu.erase(a[i2++]);
            
        }

        siuuuuu.erase(a[i1++]);
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        cout << solve(n) << endl;
    }
    return 0;
}
