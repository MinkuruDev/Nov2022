#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define fori(i,a,b) for(int i = a; i<b; i++)

using namespace std;
int dp[1002][102][102];
int t,s,c,k,d,l;

int solve(int t, int e, int sp){
    if(e<0 || sp<0) return 0;
    if(t==0) return sp;
    if(e>c) return solve(t,c,sp);
    if(dp[t][e][sp] > 0) return dp[t][e][sp];
    
    int _s = -1;
    if(sp<s)
        _s = solve(t-1,e-l,sp+1);
    if(_s > 0)
        dp[t-1][e-l][sp+1] = _s;

    int _ss = solve(t-1,e-k,sp);
    if(_ss>0)
        dp[t-1][e-k][sp] = _ss;

    int _sss = solve(t-1,e+d,sp-1);
    if(_sss > 0 && sp > 0 && e+d <= c)
        dp[t-1][e+d][sp-1] = _sss;

    dp[t][e][sp] = sp + max(max(_s, _ss), max(_sss, 0));
    // cout << dp[t][e][sp] << endl;
    return dp[t][e][sp];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t >> s >> c >> k >> l >> d;

    fori(i,0,t+1){
        fori(j,0,c*2+1){
            fori(_i,0,s+1){
                dp[i][j][_i] = 0;
            }
        }
    }
    
    cout << solve(t,c,0) << endl;

    return 0;
}
