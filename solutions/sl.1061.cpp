#include <iostream>
#include <string.h>
#include <set>
using namespace std;

string s;
set<int> states;

inline long long int getSeed(string s){
    long long int r = 0;
    for(char c : s){
        r = r * 4;
        if(c == '-') r += 1;
        else if(c == 'O') r += 2;
        else if(c == 'X') r += 3;
    }
    return r;
}

int win(string s){
    //First player
    //Vert
    if(s[0] == 'O' && s[3] == 'O' && s[6] == 'O') return 0;
    if(s[1] == 'O' && s[4] == 'O' && s[7] == 'O') return 0;
    if(s[2] == 'O' && s[5] == 'O' && s[8] == 'O') return 0;
    //Hor
    if(s[0] == 'O' && s[1] == 'O' && s[2] == 'O') return 0;
    if(s[3] == 'O' && s[4] == 'O' && s[5] == 'O') return 0;
    if(s[6] == 'O' && s[7] == 'O' && s[8] == 'O') return 0;
    //Diag
    if(s[0] == 'O' && s[4] == 'O' && s[8] == 'O') return 0;
    if(s[2] == 'O' && s[4] == 'O' && s[6] == 'O') return 0;

    //Second player
    //Vert
    if(s[0] == 'X' && s[3] == 'X' && s[6] == 'X') return 1;
    if(s[1] == 'X' && s[4] == 'X' && s[7] == 'X') return 1;
    if(s[2] == 'X' && s[5] == 'X' && s[8] == 'X') return 1;
    //Hor
    if(s[0] == 'X' && s[1] == 'X' && s[2] == 'X') return 1;
    if(s[3] == 'X' && s[4] == 'X' && s[5] == 'X') return 1;
    if(s[6] == 'X' && s[7] == 'X' && s[8] == 'X') return 1;
    //Diag
    if(s[0] == 'X' && s[4] == 'X' && s[8] == 'X') return 1;
    if(s[2] == 'X' && s[4] == 'X' && s[6] == 'X') return 1;

    return -1;
}

int tot, fp, sp, draw;

void show(string s){
    int cnt = 0;
    for(char c : s){
        cout << c << " ";
        cnt++;
        if(cnt % 3 == 0) cout << endl;
    }
    cout << endl;
}

void dfs(string s, bool player){
    if(states.count(getSeed(s))) return;
    states.insert(getSeed(s));
    //show(s);
    int res = win(s);
    char place = (player ? 'X' : 'O');
    if(res == 0){
        tot++;
        fp++;
        return;
    } else if(res == 1){
        tot++;
        sp++;
        return;
    }
    int moves = 0;
    for(char &c : s){
        if(c == '-'){
            moves++;
            c = place;
            dfs(s, player ^ 1);
            c = '-';
        }
    }
    if(!moves && res == -1){
        tot++;
        draw++;
    }
}


int main(){
    cin >> s;
    int cnt = 0;
    for(char c : s){
        if(c == 'O') cnt++;
        else if (c == 'X') cnt--;
    }
    dfs(s, cnt);
    cout << tot << " " << fp << " " << sp << " " << draw << endl;
}

