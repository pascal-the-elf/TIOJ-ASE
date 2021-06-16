#include <iostream>
#include <bitset>
using namespace std;

const int maxN = 4010;

int N, a, b, c, x, y, z, S;
bitset<maxN * maxN> visited;

inline int hsh(int a, int b){
    return maxN * a + b;
}

inline bool isValid(int a, int b){
    return (a >= 0 && b >= 0 && (S - a - b) >= 0 && a <= N && b <= N && (S - a - b) <= N);
}

bool dfs(int a, int b){
    if(!isValid(a, b)) return false;
    int c = S - a - b;
    visited[hsh(a, b)] = true;
    if(a == x && y == b && c == z) return true;
    bool r = false;
    if(!visited[hsh(b, a)]) r |= dfs(b, a); //ab
    if(!visited[hsh(c, b)]) r |= dfs(c, b); //ac
    if(!visited[hsh(a, c)]) r |= dfs(a, c); //bc
    if(isValid(2 * b - a + 1, 2 * a - b - 1) && !visited[hsh(2 * b - a + 1, 2 * a - b - 1)]) r |= dfs(2 * b - a + 1, 2 * a - b - 1);
    return r;
}

int main(){
    while(cin >> N >> a >> b >> c >> x >> y >> z){
        if(!N) return 0;
        S = (a + b + c);
        if((a + b + c) != (x + y + z)){
            cout << "No\n";
            continue;
        }
        visited.reset();
        if(dfs(a, b)){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
