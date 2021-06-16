#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int maxN = 1e4 + 10;
const double eps = 1e-8;

struct Par{
	int a, b, c; // f(x)=ax2+bx+c
	Par(){}
	Par(int a, int b, int c): a(a), b(b), c(c){}
	double y(double x){
		return a * x * x + b * x + c;
	}
};
vector<Par> pars;
int N, a, b, c;

double eval(double x){
	double res = pars[0].y(x);
	for(Par p : pars){
		res = min(res, p.y(x));
	}
	return res;
}


int main(){
	cout << fixed << setprecision(6);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b >> c;
		pars.emplace_back(a, b, c);
	}
	double l = 0, r = 100, m1, m2;
	while(r - l > eps){
		m1 = l + (r - l) / 3;
		m2 = r - (r - l) / 3;
		if(eval(m1) < eval(m2)){
			l = m1;
		} else {
			r = m2;
		}
	}
	cout << l << endl;
}
