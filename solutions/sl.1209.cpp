#include <iostream>
using namespace std;

int n, m, ds[8000005], a, b;

void flat_util(int ind){
    if(ind == ds[ind]) return;
    flat_util(ds[ind]);
    ds[ind] = ds[ds[ind]];
}

void flat(int ind){
    flat_util(ind); flat_util(2 * ind);
}

void dsuMerge(int a, int b){
    flat(a); flat(b);
    ds[ds[a]] = ds[b];
}




int main(){
    while(cin >> n >> m){
        if(!(n | m)) return 0;
        for(int i = 1; i <= 2 * n; i++) ds[i] = i;
        bool isBipartite = true;
        while(m--){
            cin >> a >> b;
            if(isBipartite){
                flat(a); flat(b);
                if(ds[a] == ds[b] || ds[b + n] == ds[a + n]){
                    isBipartite = false;
                } else {
                    dsuMerge(a, b + n); dsuMerge(b, a + n);
                }
            }
        }
        if(isBipartite){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
