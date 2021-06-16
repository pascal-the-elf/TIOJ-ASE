#include <iostream>
#include <string.h>
#include <queue>
#include <set>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct State{
    char mp[3][3];
    int x, y, stp;
    State(){}
    State(string s, int step): stp(step){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                mp[i][j] = s[3 * i + j];
                if(s[3 * i + j] == '0'){
                    x = j;
                    y = i;
                }
            }
        }
        //cout << "For " << s << ", x = " << x << ", y = " << y << endl;
    }
    long long int get(){
        long long int r = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                r = (r * 10 + mp[i][j] - '0');
            }
        }
        return r;
    }
    void show(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << mp[i][j] << " \n"[j == 2];
            }
        }
        cout << "y = " << y << ", x = " << x << endl;
    }
};

bool isValid(int y, int x){
    return (y >= 0 && x >= 0 && y < 3 && x < 3);
}

set<int> states;

void bfs(){
    queue<State> que;
    que.push(State("123456780", 0));
    State cs;
    while(que.size()){
        cs = que.front();
        que.pop();
        if(states.count(cs.get())) continue;
        states.insert(cs.get());
        //cs.show();
        if(cs.stp > 20) return;
        cs.stp++;
        if(isValid(cs.y + 1, cs.x)){
            //cout << "isvalid: down" << endl;
            swap(cs.mp[cs.y][cs.x], cs.mp[cs.y + 1][cs.x]);
            cs.y++;
            if(states.count(cs.get())){
                cs.y--;
                swap(cs.mp[cs.y][cs.x], cs.mp[cs.y + 1][cs.x]);
            } else {
                que.push(cs);
                cs.y--;
                swap(cs.mp[cs.y][cs.x], cs.mp[cs.y + 1][cs.x]);
            }
        }

        if(isValid(cs.y - 1, cs.x)){
            //cout << "isvalid: up" << endl;
            swap(cs.mp[cs.y][cs.x], cs.mp[cs.y - 1][cs.x]);
            cs.y--;
            if(states.count(cs.get())){
                cs.y++;
                swap(cs.mp[cs.y][cs.x], cs.mp[cs.y - 1][cs.x]);
            } else {
                que.push(cs);
                cs.y++;
                swap(cs.mp[cs.y][cs.x], cs.mp[cs.y - 1][cs.x]);
            }
        }

        if(isValid(cs.y, cs.x + 1)){
            //cout << "isvalid:right" << endl;
            swap(cs.mp[cs.y][cs.x], cs.mp[cs.y][cs.x + 1]);
            cs.x++;
            if(states.count(cs.get())){
                cs.x--;
                swap(cs.mp[cs.y][cs.x], cs.mp[cs.y][cs.x + 1]);
            } else {
                que.push(cs);
                cs.x--;
                swap(cs.mp[cs.y][cs.x], cs.mp[cs.y][cs.x + 1]);
            }
        }

        if(isValid(cs.y, cs.x - 1)){
            //cout << "isvalid: left" << endl;
            swap(cs.mp[cs.y][cs.x], cs.mp[cs.y][cs.x - 1]);
            cs.x--;
            if(states.count(cs.get())){
                cs.x++;
                swap(cs.mp[cs.y][cs.x], cs.mp[cs.y][cs.x - 1]);
            } else {
                que.push(cs);
                cs.x++;
                swap(cs.mp[cs.y][cs.x], cs.mp[cs.y][cs.x - 1]);
            }
        }
    }
}

int k, r;
char c;


int main(){
    ericxiao;
    bfs();
    cin >> k;
    while(k--){
        r = 0;
        for(int i = 0; i < 9; i++){
            cin >> c;
            r = r * 10 + (c - '0');
        }
        if(states.count(r)) cout << "Easy" << '\n';
        else cout << "Hard" << '\n';
    }
}
