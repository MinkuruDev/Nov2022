#include <iostream>
#include <string>
#define MAXN 100

using namespace std;
char s[MAXN];
int cnt[26], cnt2[26];

bool checkPalin(int l, int r){
    while (l < r){
        if(s[l] != s[r])
            return false;
        l++; r--;
    }
    
    return true;
}

void resetCount(){
    for(int i = 0; i<26; i++){
        cnt[i] = 0;
        cnt2[i] = 0;
    }
}

bool check(){
    for(int i = 0; i<26; i++){
        if(cnt[i] != cnt2[i])
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t,n,k;
    cin >> t;
    while (t--){
        cin >> n >> k;
        cin >> s;
        if(!checkPalin(k, n-k-1)){
            cout << "No" << endl;
            continue;
        }

        resetCount();
        for(int i = 0; i<k; i++){
            cnt[s[i]-'a']++;
            int j = n-i-1;
            cnt2[s[j]-'a']++;
        }
        if(!check()){
            cout << "No" << endl;
            continue;
        }

        for(int i = 0; i<k; i++){
            s[i] = s[n-i-1];
        }
        cout << "Yes\n" << s << endl;
    }
    
    return 0;
}
