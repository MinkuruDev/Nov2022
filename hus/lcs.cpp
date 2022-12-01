#include <iostream>
#include <string>

using namespace std;

int dp[5002][5002];

int lcs(string& s1, string& s2){
    int n = s1.size();
    int m = s2.size();
    for(int i = 0; i<=n; i++)
        dp[i][0] = 0;
    for(int i = 1; i<=m; i++)
        dp[0][i] = 0;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    return dp[n][m];
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
    return 0;
}
