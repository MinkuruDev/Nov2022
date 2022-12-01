#include <iostream>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    ordered_multiset segs;
    cout << fixed << showpoint << setprecision(1);

    for(int i = 1; i<=n; i++){
        int j;
        cin >> j;
        segs.insert(j);
        double res = 0;
        if(i%2 == 0){
            res += *segs.find_by_order(i/2);
            res += *segs.find_by_order(i/2-1);
            res /= 2;
        }else{
            res = *segs.find_by_order(i/2);
        }

        cout << res << endl;
    }

    return 0;
}
