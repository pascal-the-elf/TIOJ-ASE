#include <iostream>
#include <complex>
#include <utility>
#define pii pair<int,int>
#define Re first
#define Im second
#define ll __int128
#define cll pair<__int128,__int128>
using namespace std;

long long int a, b;

inline ll abs(ll a){
    return a > 0 ? a : -a;
}

inline ll round(ll a, ll b){ //return round(a/b)
    ll sgn = ((a * b) > 0 ? 1 : -1);
    a = abs(a);
    b = abs(b);
    ll cei = (a + b - 1) / b, fl = a / b;
    if((cei + fl) * b <= 2 * a){
        return cei * sgn;
    } else{
        return fl * sgn;
    }
}

inline ll norm(cll c){
    return (c.Re * c.Re) + (c.Im * c.Im);
}

inline cll conj(cll c){
    return {c.Re, -c.Im};
}

cll operator*(cll a, cll b){
    return {a.Re * b.Re - a.Im * b.Im, a.Re * b.Im + a.Im * b.Re};
}

cll operator/(cll a, cll b){
    cll r = a * conj(b);
    return {round(r.Re, norm(b)), round(r.Im, norm(b))};
}

cll operator+(cll a, cll b){
    return {a.Re + b.Re, a.Im + b.Im};
}

cll operator-(cll a, cll b){
    return {a.Re - b.Re, a.Im - b.Im};
}

cll gcd(cll a, cll b){
    if(b.Re == 0 && b.Im == 0) return a;
    return gcd(b, a - ((a / b) * b));
}

cll G = {0, 0};

int main(){
    for(int i = 0; i < 6; i++){
        cin >> a >> b;
        G = gcd(G, {(ll)a, (ll)b});
    }
    cout << (long long int)(abs(G.Re) + abs(G.Im)) << endl;
}
