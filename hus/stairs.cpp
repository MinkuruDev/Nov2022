#include <iostream>

using namespace std;

int main(){
    int dp[50];
    dp[1] = 1; 
    dp[2] = 2;
    int n;
    cin >> n;
    for(int i = 3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << endl;
    return 0;
}
