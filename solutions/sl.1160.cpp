#include <iostream>
#include <map>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;


map<int, int> frq;
int ans, x;

int main(){
    while(cin >> x){
        if(!x) return 0;
        frq[x]++;
        if(frq[x] > frq[ans] || (frq[x] == frq[ans] && x < ans)){
            ans = x;
        }
        cout << frq[ans] << " " << ans << endl;
    }
}
