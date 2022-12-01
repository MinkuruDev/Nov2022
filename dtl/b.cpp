#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define ll long long
#define fori(i,a,b) for(int i = a; i<b; i++)

using namespace std;

int a[100002];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        ll m = (ll)1e18;
        int idx = 0;
        fori(i,1,n+1){
            cin >> a[i];
            if(n%2==0){
                if(i%2==0)
                    continue;
                ll l = 1ll * n * a[i] + i;
                if(l < m){
                    m = l;
                    idx = i-1; 
                }
            }else{
                ll l;
                if(i%2 == 0)
                    l = 1ll * 2 * n * a[i] + n + i;
                else
                    l = 1ll * 2 * n * a[i] + i;
                if(l < m){
                    m = l;
                    idx = i-1; 
                }
            }
        }

        cout << idx << endl;
    }
    return 0;
}
