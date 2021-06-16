#include <iostream>
#include <algorithm>
using namespace std;
//By S
long long int i, j;

int main(){
    while(cin >> i>> j){
        if(!(i | j)) return 0;
        if(i > j) swap(i, j);
        long long int ans = (i + 1)*(i + 1)*(j + 1) - (i + 1)*(i + 2)*(i + j + 2)/2 + (i + 1)*(i + 2)*(2 * i + 3)/6;
        printf("%lld\n", ans);

    }
}
