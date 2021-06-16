#include <iostream>
#include <unordered_map>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e3 + 10;

int pre[maxN][maxN][3], N, a, b, c, d, dr, dg, db, colours, R, G, B; //(a, b) to (c, d)
short cols[maxN][maxN];

string hsh(int x, int y, int z){
    //cout << "Hashing " << endl;
    return to_string(x) + "/" + to_string(y) + "/" + to_string(z);
}

unordered_map<string, int> mp;

int main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c >> d >> dr >> dg >> db;
        if(!dr && !dg && !db) continue;
        if(a > c) swap(a, c);
        if(b > d) swap(b, d);
        for(int j = a; j <= c; j++){
            pre[j][b][0] += dr;
            pre[j][d + 1][0] -= dr;

            pre[j][b][1] += dg;
            pre[j][d + 1][1] -= dg;

            pre[j][b][2] += db;
            pre[j][d + 1][2] -= db;

            cols[j][b]++;
            cols[j][d + 1]--;
        }
    }
    //cout << "DOne pre" << endl;
    for(int i = 0; i < maxN; i++){
        colours = R = G = B = 0;
        for(int j = 0; j < maxN; j++){
            //cout << "i = " << i << ", j = " << j << '\n';
            colours += cols[i][j];
            R += pre[i][j][0];
            G += pre[i][j][1];
            B += pre[i][j][2];
            if(colours > 0){
                //cout << "R = " << R << ", G = " << G << ", B = " << B << ", cols = " << colours << endl;
                mp[hsh((R + colours - 1)/colours, (G + colours - 1)/colours, (B + colours - 1)/colours)]++;
                //cout << "Done" << endl;
            }
        }
    }
    int mx = 0;
    string ans = "";
    for(auto item : mp){
        //if(item.first == "0/0/0") continue;
        if(mx < item.second){
            mx = item.second;
            ans = item.first;
        }
    }
    //cout << ans << endl;
    string cs = "";
    for(char c : ans){
        if(c == '/'){
            cout << stoi(cs) << " ";
            cs = "";
        } else {
            cs += c;
        }
    }
    cout << stoi(cs) << endl;
}
