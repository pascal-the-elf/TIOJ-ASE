#include <iostream>
using namespace std;

int dirs[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
}, x = 10, y = 5, dir = 0, lft = 5, ans[120][2], T;

void step(){
    for(int i = 0; i < 6; i++){
        if(!lft){
            lft = 10;
            dir = (dir + 1) % 4;
        }
        x += dirs[dir][0];
        y += dirs[dir][1];
        lft--;
    }
}

int main(){
    for(int t = 0; t < 120; t++, step()){
        ans[t][0] = x;
        ans[t][1] = y;
    }
    while(cin >> T){
        T %= 120;
        cout << "(" << ans[T][0] << "," << ans[T][1] << ")" << endl;
    }

}
