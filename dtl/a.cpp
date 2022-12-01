#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define fori(i,a,b) for(int i = a; i<b; i++)

using namespace std;
int a[102];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        fori(i,0,n){
            cin >> a[i];
        }
        sort(a,a+n);
        fori(i,1,n){
            a[i] += a[i-1];
        }
        int ans = 0;
        for(int i = n-1; i>=2; i--){
            if(a[i]-a[i-1] < a[i-1]){
                ans = a[i];
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
