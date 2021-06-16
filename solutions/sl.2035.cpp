#pragma GCC optimize ("O3") //because I can get the runtime to be 0ms, why not
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
//By S
int b;
string N;

int convertToDec(){
    int l = N.length(), ans = 0;
    for(int i = 0; i < l; i++){
        ans += (N[i] - '0');
        ans *= b;
    }
    return ans/b;
}

int get(){
    int l = N.length(), ans = 0;
    for(int i = 0; i < l; i++){
        ans += pow(N[i] - '0', l);
    }
    return ans;
}

int main(){
    cin >> b >> N;
    if(get() == convertToDec()) printf("YES\n");
    else printf("NO\n");
}
