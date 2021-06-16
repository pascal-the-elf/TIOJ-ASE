#include <iostream>
#include <deque>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 500 + 26, fact = 3, INF = 1e4;
int N, a, b, c, d, x, has[maxN], ans = 0, cnt, pm = -1;

struct Line{
	int X1, Y1, X2, Y2, id;
	Line(){}
	Line(int a, int b, int c, int d, int i): X1(a), Y1(b), X2(c), Y2(d), id(i){
		if(X1 > X2){
			swap(X1, X2);
			swap(Y1, Y2);
		}
	}
	inline void disp(){
		cout << "Line: (" << X1 << ", " << Y1 << ") - (" << X2 << ", " << Y2 << ")\n"; 
	}
} lines[maxN];

deque<Line> dq;



signed main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b >> c >> d;
		a *= fact;
		b *= fact;
		c *= fact;
		d *= fact; //hulan lol, will AC with fact = 3
		lines[i] = Line(a, b, c, d, i);
	}
	sort(lines, lines + N, [=](Line a, Line b){
		return a.X1 < b.X1;	
	});
	for(x = 0; x <= 10000 * fact; x++){
		while(cnt < N && lines[cnt].X1 == x){
			dq.push_back(lines[cnt++]);
			//cout << "pushing " << cnt - 1 << " at x = " << x << endl;
		}
		sort(dq.begin(), dq.end(), [=](Line a, Line b){
			//cout << "A:" << endl;
			//a.disp();
			//cout << "B:" << endl;
			//b.disp();
			//cout << "A: " << ( (b.X2 - b.X1) * (a.Y1 * (a.X2 - a.X1) + (x - a.X1) * (a.Y2 - a.Y1)) ) << endl;
			//cout << "B: " << ((a.X2 - a.X1) * (b.Y1 * (b.X2 - b.X1) + (x - b.X1) * (b.Y2 - b.Y1)) ) << endl;
			//cout << ((b.X2 - b.X1) * (a.Y1 * (a.X2 - a.X1) + (x - a.X1) * (a.Y2 - a.Y1)) < (a.X2 - a.X1) * (b.Y1 * (b.X2 - b.X1) + (x - b.X1) * (b.Y2 - b.Y1))) << endl;
			if(a.X2 < x) return false;
			if(b.X2 < x) return true;
			return (b.X2 - b.X1) * (a.Y1 * (a.X2 - a.X1) + (x - a.X1) * (a.Y2 - a.Y1)) < (a.X2 - a.X1) * (b.Y1 * (b.X2 - b.X1) + (x - b.X1) * (b.Y2 - b.Y1)); 
		});
		//cout << "For x = " << x << endl;
		//for(Line l : dq){
		//	l.disp();
		//}
		while(dq.size() && dq.back().X2 < x) dq.pop_back();
		if(dq.size() && dq.front().id != pm){
			//cout << "new:" << dq.front().id << " has min at x = " << x << endl;
			ans++;
			pm = dq.front().id;
		}
	}
	cout << ans << endl;
}
