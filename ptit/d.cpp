#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#define fori(i,a,b) for(int i = a; i<b; i++)
#define MAXN 500002
#define ll long long

using namespace std;

vector<int> g[MAXN];
int classs[MAXN], cnt[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    fori(i,1,n+1){
        cin >> classs[i];
    }
    int u,v;
    fori(i,0,m){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    fori(i,1,n+1){
        fori(j,i+1,n+1){
            cnt[j] = 0;
        }

        
        for(int j: g[i]){
            
        }
    }
    return 0;
}
