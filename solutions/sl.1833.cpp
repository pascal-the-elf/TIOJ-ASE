#include <iostream>
#include <string.h>
#include <numeric>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 100100;

int n, m, a, b, dsu[maxN];
string s;

void Flat(int x){
    if(x == dsu[x]) return;
    Flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

void Merge(int a, int b){
    Flat(a);
    Flat(b);
    if(dsu[a] == dsu[b]) return;
    dsu[dsu[b]] = dsu[a];
}

int main(){
    ericxiao;
    cin >> n >> m;
    iota(dsu, dsu + n + 1, 0);
    while(m--){
        cin >> s;
        if(s[0] == 'M'){
            cin >> a >> b;
            Merge(a, b);
        } else {
            cin >> a;
            Flat(a);
            cout << dsu[a] << '\n';
        }
    }
}
