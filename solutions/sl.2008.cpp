#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5; //not sure if this is enough

int n = 0;
vector<int> wins, ad, def;

void go(vector<int> eq, vector<int> lar){//must have <= in the eq thingy and < in the lar thingy
    vector<int> res;
    res.resize(n);
    stack<pii> seq, slar;
    int ceq, clar, weq = 0, wlar = 0;
    for(int i = 0; i < n; i++){

        ceq = eq[i];
        clar = lar[i];
        weq = 0, wlar = 0;
        cout << "ceq = " << ceq << ", clar = " << clar << endl;
        while(seq.size() && seq.top().F < ceq){
            weq += seq.top().S;
            seq.pop();
        }
        if(seq.size() && seq.top().F == ceq){
            weq += seq.top().S;
            seq.top().S++;
        } else {
            seq.push({ceq, 1});
        }

        while(slar.size() && slar.top().F < clar){
            wlar += slar.top().S;
            slar.pop();
        }
        if(slar.size() && slar.top().F == clar){
            slar.top().S++;
        } else {
            slar.push({clar, 1});
        }
        res[i] = min(wlar, weq);
        cout << "For i = " << i << ", weq = " << weq << ", wlar = " << wlar << endl;
    }
    for(int i = 0; i < n; i++) wins[i] += res[i];
};

void bothBig(vector<int> eq, vector<int> lar){
    vector<int> res;
    res.resize(n);
    stack<pii> seq, slar;
    int ceq, clar, weq = 0, wlar = 0;
    for(int i = 0; i < n; i++){
        ceq = eq[i];
        clar = lar[i];
        weq = 0, wlar = 0;
        while(seq.size() && seq.top().F < ceq){
            weq += seq.top().S;
            seq.pop();
        }
        if(seq.size() && seq.top().F == ceq){
            seq.top().S++;
        } else {
            seq.push({ceq, 1});
        }

        while(slar.size() && slar.top().F < clar){
            wlar += slar.top().S;
            slar.pop();
        }
        if(slar.size() && slar.top().F == clar){
            slar.top().S++;
        } else {
            slar.push({clar, 1});
        }
        res[i] = min(wlar, weq);
    }
    for(int i = 0; i < n; i++) wins[i] -= res[i];
}

int main(){
    ericxiao;
    cin >> n;
    wins.resize(n);
    ad.resize(n);
    def.resize(n);
    for(int i = 0; i < n; i++){
        cin >> ad[i] >> def[i];
    }
    cout << "Running go(ad, def)" << endl;
    go(ad, def);
    go(def, ad);
    bothBig(def, ad);
    reverse(ad.begin(), ad.end());
    reverse(def.begin(), def.end());
    go(ad, def);
    go(def, ad);
    bothBig(def, ad);
    int mx = 0;
    for(int i = 0; i < n; i++){
        cout << "wins[" << i << "] = " << wins[i] << endl;
        mx = max(mx, wins[i]);
    }
    cout << mx << endl;
}
