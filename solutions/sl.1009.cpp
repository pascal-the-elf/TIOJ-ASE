#include <iostream>
#include <string.h>
using namespace std;

string t;

inline int parse(string s){
    return (3600 * stoi(s.substr(0, 2)) + 60 * stoi(s.substr(3, 2)) + stoi(s.substr(6, 2)));
}

inline void print(int x){
    printf("%02d:%02d:%02d\n", x / 3600, (x % 3600) / 60, x % 60);
}

int main(){
    cin >> t;
    int st = parse(t);
    cin >> t;
    int ed = parse(t);
    print((ed - st + 86400) % 86400);

}
