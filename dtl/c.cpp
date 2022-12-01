#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define fori(i,a,b) for(int i = a; i<b; i++)

using namespace std;

struct ST{
    int e,v,d;
    
    // ST():e(0),v(0),d(0){};

    ST operator+(const ST& other){
        return {
            e+other.e,
            v+other.v,
            d+other.d
        };
    }

    bool operator>(const ST& other){
        if(d==other.d){
            if(v==other.v){
                return e > other.e;
            }
            return v>other.v;
        }
        return d>other.d;
    }

} dp[1002][4];

int main(){
    int t,s,c,k,d,l;
    cin >> t >> s >> c >> k >> l >> d;
    fori(i,0,4){
        dp[0][i] = {c,0,0};
    }

    fori(i,1,t+1){
        fori(j,0,4)
            dp[i][j] = {0,0,0};
        fori(j,0,4){
            // stop
            ST temp = dp[i-1][j] + ST({d,0,0});
            temp.v = 0;
            if(temp.e > c)
                temp.e = c;
            if(temp > dp[i][0])
                dp[i][0] = temp;

            // speed-1
            temp = dp[i-1][j] + ST({d,-1,0});
            if(temp.v < 0)
                temp.v = 0;
            temp.d += temp.v;
            if(temp.e > c)
                temp.e = c;
            if(temp > dp[i][1])
                dp[i][1] = temp;

            // speed =
            temp = dp[i-1][j] + ST({-k,0,0});
            if(temp.e >= 0){
                temp.d += temp.v;
                if(temp > dp[i][2])
                    dp[i][2] = temp;
            }

            // speed +1
            temp = dp[i-1][j] + ST({-l,1,0});
            if(temp.v > s){
                dp[i][3] = dp[i][2];
                continue;
            }
            if(temp.e >= 0){
                temp.d += temp.v;
                if(temp > dp[i][3])
                    dp[i][3] = temp;
            }
        }
    }

    int ans = 0;
    fori(i,0,4){
        ans = max(ans, dp[t][i].d);
    }

    cout << ans << endl;

    return 0;
}
