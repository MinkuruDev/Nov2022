#include <iostream>
#include <string>
#include <map>

using namespace std;

int di[] = {-2,-2,0,2,2,0};
int dj[] = {-1,1,2,1,-1,-2};
map<string, int> direction;
string res;
int n;

bool inside(int i, int j){
    if(i<0 || i>=n) return false;
    if(j<0 || j>=n) return false;
    return true;
}

bool Move(int &x, int &y, string dir){
    int i = direction[dir];
    if(!inside(x+di[i], y+dj[i]))
        return false;
    x += di[i];
    y += dj[i];
    // cout << dir << endl;
    res += dir + " ";
    return true;
}

int main(){
    int is,js,ie,je;
    cin >> n >> is >> js >> ie >> je;

    if(abs(ie-is)%2 == 1 || abs((ie-is)/2 - (je-js))%2 == 1){
        cout << "Impossible" << endl;
        return 0;
    }

    string dir[] = {"UL", "UR", "R", "LR", "LL", "L"};
    for(int i = 0; i<6; i++)
        direction[dir[i]] = i;

    int moves = 0;

    while(is != ie){
        if(is < ie){
            if(js > je){
                Move(is,js,"LL");
            }else{
                if(!Move(is,js,"LR"))
                    Move(is,js,"LL");
            }
        }else{
            if(js < je){
                Move(is,js,"UR");
            }else{
                if(!Move(is,js,"UL"))
                    Move(is,js,"UR");
            }
        }

        moves++;
    }

    while(js > je){
        Move(is,js,"L");
        moves++;
    }
    while(js < je){
        Move(is,js,"R");
        moves++;
    }
    
    cout << moves << endl;
    cout << res << endl;

    return 0;
}
