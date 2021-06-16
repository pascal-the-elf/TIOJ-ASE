#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

struct Frac{
    int a, b;
    Frac(){}
    Frac(int a, int b):a(a), b(b){
        int g = gcd(a, b);
        a /= g, b /= g;
    }
    bool operator<(const Frac f) const {
        return a*f.b > f.a*b;
    }
};

vector<Frac> fs[71];

void init(){
    for(int i = 2; i <= 70; i++){
        for(Frac f : fs[i - 1]) fs[i].push_back(f);
        for(int j = 1; j < i; j++){
            if(gcd(i, j) == 1) fs[i].push_back(Frac(j, i));
        }
        sort(fs[i].begin(), fs[i].end());
    }
}

int main(){
    init();
    int N;
    cin >> N;
    cout << fs[N].size() << endl;
    if(fs[N].size() < N) cout << fs[N][0].a << "/" << fs[N][0].b << endl;
    else cout << fs[N][fs[N].size() - N].a << "/" << fs[N][fs[N].size() - N].b << endl;
}
