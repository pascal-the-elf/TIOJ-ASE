#include <iostream>
using namespace std;

const int maxN = 1e3 + 10;

int N, M, arr[maxN][maxN], _arr[maxN][maxN], maxV[maxN], minV[maxN], l, r, u, d, L, ans;
bool can = true;


inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}

struct Queue{
    int a, b, dq[maxN * 2];
    Queue(){
        a = b = 0;
    }
    inline void push(int x){
        dq[b++] = x;
    }
    inline void pop_front(){
        a++;
    }
    inline void pop_back(){
        b--;
    }
    inline int front(){
        return dq[a];
    }
    inline int back(){
        return dq[b - 1];
    }
    inline bool empty(){
        return (a >= b);
    }
} minQ, maxQ;


int main(){
    Read(N);
    Read(M);
    Read(L);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            Read(arr[i][j]);
        }
    }

    for(r = 0; r < M; r++){
        for(int i = 0; i < N; i++) maxV[i] = minV[i] = arr[i][r];
        for(l = r; l >= 0; l--){
            if(N * (r - l + 1) <= ans) continue;
            for(int i = 0; i < N; i++){
                if(arr[i][l] > maxV[i]) maxV[i] = arr[i][l];
                if(arr[i][l] < minV[i]) minV[i] = arr[i][l];
            }
            minQ = Queue();
            maxQ = Queue();
            u = d = 0;
            for(d = 0; d < N; d++){
                while(!minQ.empty() && minV[minQ.back()] >= minV[d]) minQ.pop_back();
                while(!maxQ.empty() && maxV[maxQ.back()] <= maxV[d]) maxQ.pop_back();
                minQ.push(d);
                maxQ.push(d);
                while(!minQ.empty() && !maxQ.empty() && maxV[maxQ.front()] - minV[minQ.front()] > L){
                    while(!minQ.empty() && minQ.front() == u) minQ.pop_front();
                    while(!maxQ.empty() && maxQ.front() == u) maxQ.pop_front();
                    u++;
                }
                //if((N - u + 1) * (r - l + 1) >= ans) break;
                if(ans < (r - l + 1) * (d - u + 1)) ans = (r - l + 1) * (d - u + 1);
            }
        }
    }
    cout << ans << '\n';
}
