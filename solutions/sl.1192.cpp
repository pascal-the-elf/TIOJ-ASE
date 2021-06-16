#include <iostream>
#include <vector>
#include <numeric>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define gc getchar_unlocked
using namespace std;

const int maxL = 1e6 + 10, maxN = 2260;

vector<int> aos[maxL], tus[maxL], dsu;
int T, N, L, k;

void init();
void Flat(int x);
bool Merge(int a, int b);

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main(){
    ericxiao;
    scanint(T);
    while(T--){
        scanint(N);
        scanint(L);
        init();
        bool can = true;
        for(int i = 0; i < N; i++){
            //ao
            scanint(k);
            while(k){
                for(int x : tus[k]){
                    Merge(x, i + N);
                    Merge(x + N, i);
                }
                aos[k].push_back(i);
                scanint(k);
            }
            //tu
            scanint(k);
            while(k){
                for(int x : aos[k]){
                    if(x == i) continue;
                    Merge(x, i + N);
                    Merge(x + N, i);
                }
                tus[k].push_back(i);
                scanint(k);
            }
        }
        for(int i = 0; i < N; i++){
            Flat(i);
            Flat(i + N);
            can &= (dsu[i] != dsu[i + N]);
        }
        cout << (can ? "Yes" : "No") << '\n';
    }
}

void Flat(int x){
    if(x == dsu[x]) return;
    Flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

bool Merge(int a, int b){
    Flat(a);
    Flat(b);
    if(dsu[a] == dsu[b]) return false;
    dsu[dsu[a]] = dsu[b];
    return true;
}

void init(){
    for(int i = 0; i < L; i++){
        vector<int>().swap(aos[i]);
        vector<int>().swap(tus[i]);
    }
    dsu.resize(2 * N + 2);
    iota(dsu.begin(), dsu.end(), 0);
}
