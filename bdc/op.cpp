#include <iostream>

#define MAXN 100

using namespace std;

int a[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    int max = 0, min = 1000000002;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];
    }
    int t;
    while (q--)
    {
        cin >> t;
        cout << ((t>=min && t<=max)? "Yes" : "No") << endl;
    }
    
    return 0;
}
