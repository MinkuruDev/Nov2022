#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n <= 3){
            for(int i = 1; i<=n; i++)
                cout << i << " ";
            cout << endl;
            continue;
        }

        int dis = n/2;
        for(int i = dis; i>=1; i--){
            int _i = i;
            while(_i <= n){
                cout << _i << " ";
                _i += dis;
            }
        }
        cout << endl;
    }
    
    return 0;
}
