#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#define fori(i,a,b) for(int i = a; i<b; i++)
#define MAXN 200002
#define ll long long

using namespace std;

ll a[MAXN];
vector<int> res, lis;
map<int, int> loc;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int last = 0;
    fori(i,0,n){
        cin >> a[i];
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if(it == lis.end()){
            lis.push_back(a[i]);
        }else{
            loc.erase(*it);
            *it = a[i];
        }
        loc[a[i]] = i;
    }

    for(int i = n-2; i>=0; i--)
        a[i] += a[i+1];
    
    int i = 1;
    double m = 0;
    for(auto it: loc){

        while(i <= it.second && i<=n-2){
            double avg = (double)(a[i]-it.first)/(n-i-1);
            // cout << avg << endl;
            if(avg == m)
                res.push_back(i);
            if(avg > m){
                m = avg;
                vector<int> emp;
                swap(res, emp);
                res.push_back(i);
            }

            i++;
        }
    }
    for(auto it: res){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
