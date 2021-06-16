#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

struct Node{
	double frq;
	Node *l, *r;
	Node(double x): frq(x), l(NULL), r(NULL){}
	Node(Node *l, Node *r): frq(l->frq + r->frq), l(l), r(r){}
} *a, *b;

class Cmp{
public:
	const bool operator()(const Node *a, const Node *b) const {
		return a->frq > b->frq;
	}
};

priority_queue<Node*, vector<Node*>, Cmp> pq;

int N;
char c;
double frq, ans;

void dfs(Node *n, int dep = 0){
	if(!n->l && !n->r){
		ans += n->frq * dep; 
		return;
	}
	dfs(n->l, dep + 1);
	dfs(n->r, dep + 1);
}

int main(){
	cout << fixed << setprecision(2);
	cin >> N;
	while(N--){
		cin >> c >> frq;
		pq.push(new Node(frq));
	}
	while(pq.size() > 1){
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();	
		pq.push(new Node(a, b));
	}
	dfs(pq.top());
	cout << ans << endl;
}
