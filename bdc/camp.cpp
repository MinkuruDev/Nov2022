#include <iostream>
#include <utility>
#include <algorithm>

#define MAXN 100
#define ll long long

using namespace std;

struct Point{
    ll x,y;
    bool operator<(const Point& other){
        if(x == other.x)
            return y < other.y;
        return x < other.x;
    }
};

Point points[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    ll sum = 0;
    for(int i = 0; i<n; i++){
        cin >> points[i].x >> points[i].y;
        sum += points[i].y;
    }

    sort(points, points+n);
    int i = 0, j = n-1;
    sum -= points[j].x - points[i].x;
    while (i < j){
        if(i+1==j){
            sum = max(sum, max(points[i].y-points[i].x, points[j].y-points[j].x));
            break;
        }
        bool flag = false;

        /*
        2  3
        4  5
        10 2
        */

        int _i = i;
        ll s = 0;
        while(_i < j-1){
            s -= points[_i].y; // loss
            s += points[_i+1].x-points[i].x; // gain
            
            if(s > 0){
                sum += s;
                flag = true;
                i = _i + 1;
                break;
            }
            _i++;
        }
        if(flag) continue;
        
        int _j = j;
        s = 0;
        while(_j > i+1){
            s -= points[_j].y; // loss
            s += points[j].x-points[_j-1].x; // gain
            
            if(s > 0){
                sum += s;
                flag = true;
                j = _j - 1;
                break;
            }
            _j--;
        }

        if(!flag) break;
    }
    cout << sum << endl;
    return 0;
}
