#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10, maxLog = 17;

int N, arr[maxN], l, r;
inline char readchar(){
	static const int size = 1 << 16;
	static char buf[size], *p = buf, *e = buf;
	if(p == e && (p = buf) == (e = fread(buf, sizeof(char), size, stdin) + buf))return EOF;
	return *p++;
}
template<class T>
void read(T &v){
	static char p;
	bool minus = false;
	while(!isdigit(p = readchar()))minus = p == '-';
	v = p ^ '0';
	while(isdigit(p = readchar())) v *= 10, v += p ^ '0';
}

struct RMQ{
    int sparse[maxLog][maxN * 2];
    RMQ(){
        for(int i = 0; i < N; i++) sparse[0][i] = arr[i];
        for(int d = 1; (1 << d) <= N; d++){
            for(int i = 0; i + (1 << d) - 1 < N; i++){
                sparse[d][i] = min(sparse[d - 1][i], sparse[d - 1][i + (1 << (d - 1))]);
            }
        }
    }
    int query(int l, int r){
        int k = (r - l), d = 0;
        while((1 << d) < k) d++;
        d--;
        return min(sparse[d][l], sparse[d][r - (1 << d)]);
    }
};

int main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        arr[i]++;
    }
    RMQ rmq = RMQ();
    while(cin >> l >> r){
        cout << rmq.query(l - 1, r) << endl;
    }
}
