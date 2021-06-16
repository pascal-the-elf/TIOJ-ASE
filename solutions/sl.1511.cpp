#include <iostream>
#include <string.h>
#include <iomanip>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

unsigned long long int n, R, O, A;
string a, b;

inline unsigned long long int c3(unsigned long long int x){
    unsigned long long int a = x, b = x - 1, c = x - 2;
    if((a % 2) == 0) a /= 2;
    else if((b % 2) == 0) b /= 2;
    else if((c % 2) == 0) c /= 2;

    if((a % 3) == 0) a /= 3;
    else if((b % 3) == 0) b /= 3;
    else if((c % 3) == 0) c /= 3;

    return a * b * c;
}

int main(){
    ericxiao;
    while(cin >> n >> a >> b){
        R = ((n & 1) ? 0 : (n / 2) * (n - 2));
        O = n * ((n - n/2 - 2) * (n - n/2 - 1) / 2);
        A = c3(n) - R - O;
        if(a[0] == 'R'){
            cout << R;
        } else if(a[0] == 'A') {
            cout << A;
        } else {
            cout << O;
        }
        cout << '\n';
    }
}
