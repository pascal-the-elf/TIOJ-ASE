#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 10;

int T, gc = 0;
string a, b;

inline int getId(char c){
    if(c == 'R') return 0;
    if(c == 'P') return 1;
    if(c == 'S') return 2;
    return -1;
}

vector<pii> where;
vector<int> groups[maxN];
vector<int> pre[maxN][3]; //ijk: ith group, jth symbol, kth prefix
int main(){
    ericxiao;
    cin >> T >> a >> b;
    bool hS = false;
    if(a.length() > b.length()){
        swap(a, b);
        hS = true;
    }
    where.resize(b.length());
    fill(where.begin(), where.end(), pii({-1, -1}));
    int cg, ind, w = 0, l = 0, d = 0;
    for(int i = 0; i < a.length(); i++){
        if(where[i].F != -1) continue;
        cg = gc++, ind = i;
        while(where[ind].F == -1){
            where[ind] = {cg, groups[cg].size()};
            groups[cg].push_back(ind);
            ind = ( ind + a.length() ) % b.length();
        }
    }
    for(int g = 0; g < gc; g++){
        //cout << "g = " << g << endl;
        pre[g][0].resize(groups[g].size());
        pre[g][1].resize(groups[g].size());
        pre[g][2].resize(groups[g].size());
        pre[g][0][0] = pre[g][1][0] = pre[g][2][0] = 0;
        pre[g][getId(b[groups[g][0]])][0]++;
        for(int i = 1; i < groups[g].size(); i++){
            for(int j = 0; j < 3; j++) pre[g][j][i] = pre[g][j][i - 1];
            pre[g][getId(b[groups[g][i]])][i]++;
        }
    }
    //cout << "A" << endl;
    int jf, tlt, rem, frqs[3], myId;
    for(int i = 0; i < a.length(); i++){
        if(i >= T) continue;
        jf = (T - i - 1) / a.length() + 1;
        //ijk: ith group, jth symbol, kth prefix
        //group index: groups[where[i].F]
        //position in group: where[i].S
        //want to loop forward (T - i) / a.length() times
        //total loop time:
        /*
        (group.size() - [group pos]) + tlt * |group| <= jf
        tlt = (jf - group.size() + [group pos]) / |group|
        remaining number to go: jf - ((group.size() - [group pos]) + tlt * |group|)
        */
        if(jf + where[i].S >= groups[where[i].F].size()){
            tlt = (jf - (groups[where[i].F].size() - where[i].S)) / groups[where[i].F].size();
            rem = jf - (groups[where[i].F].size() - where[i].S + tlt * groups[where[i].F].size());
            for(int j = 0; j < 3; j++){
                frqs[j] = pre[where[i].F][j][groups[where[i].F].size() - 1] * (tlt + 1) + (rem ? pre[where[i].F][j][rem - 1] : 0) - (where[i].S ? pre[where[i].F][j][where[i].S - 1] : 0);
            }
            /*
            cout << "Total Rotations: " << tlt << " with " << rem << " remaining" << endl;
            cout << "Beginning: ";
            for(int j = 0; j < 3; j++) cout << pre[where[i].F][j][groups[where[i].F].size() - 1] - (where[i].S ? pre[where[i].F][j][where[i].S - 1] : 0) << " ";
            cout << endl;
            cout << "Total Recurse: ";
            for(int j = 0; j < 3; j++) cout << pre[where[i].F][j][groups[where[i].F].size() - 1] * tlt << " ";
            cout << endl;
            cout << "Remaining: ";
            for(int j = 0; j < 3; j++) cout << (rem ? pre[where[i].F][j][rem - 1] : 0) << " ";
            cout << endl;
            */
        } else {
            //cout << "is within: frqs ";
            for(int j = 0; j < 3; j++){
                frqs[j] = pre[where[i].F][j][jf + where[i].S - 1] - (where[i].S ? pre[where[i].F][j][where[i].S - 1] : 0);
                //cout << frqs[j] << " ";
            }
            //cout << endl;
        }

        myId = getId(a[i]);
        w += frqs[(myId + 2) % 3];
        l += frqs[(myId + 1) % 3];
        d += frqs[(myId) % 3];
    }
    if(!hS){
        cout << w << " " << l << " " << d << endl;
    } else {
        cout << l << " " << w << " " << d << endl;
    }

    /*
    100
    RRR
    PPPP

    1
    S
    RPPPSPPRSS
    */
}
